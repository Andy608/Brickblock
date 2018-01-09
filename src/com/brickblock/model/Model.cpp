#include "Model.h"
#include "../util/math/MatrixUtil.h"
#include "../util/logger/BBLogger.h"
#include "../util/load/resource/mesh/Mesh.h"
#include "../util/math/physics/Transform.h"
#include "../util/load/resource/mesh/util/TextureWrapper.h"
#include <glm/gtc/type_ptr.hpp>
using namespace bb;

Model::Model() :
	mModelTransform(new Transform()),
	mTextureWrapper(nullptr)
{

}

Model::~Model()
{
	//unload();

	delete mModelTransform;

	if (mTextureWrapper != nullptr)
	{
		delete mTextureWrapper;
	}
}

/*void Model::load()
{
	if (mIsLoaded)
	{
		return;
	}

	loadComponents(mRoot);
	mIsLoaded = GL_TRUE;
}

void Model::loadComponents(ComponentNode *node)
{
	std::vector<ComponentNode*> *children = mRoot->mChildNodes;

	if (children != nullptr)
	{
		GLuint i;
		GLuint childrenAmount = children->size();

		for (i = 0; i < childrenAmount; ++i)
		{
			loadComponents(children->at(i));
		}
	}

	//The meshes should be loaded up already
	//from a mesh manager somewhere else. 
	//This may not need to be here.
	Mesh *currentMesh = mRoot->mMesh;

	if (currentMesh != nullptr)
	{
		currentMesh->load();
	}
}

void Model::unload() 
{
	if (mRoot != nullptr)
	{
		mRoot->clearComponents();
	}

	mIsLoaded = GL_FALSE;
}*/


/*void Model::renderComponents(ComponentNode *node, const ShaderProgram &activeShader, const GLdouble &DELTA_TIME)
{
	std::vector<ComponentNode*> *children = node->mChildNodes;

	if (children != nullptr)
	{
		GLuint i;
		GLuint childrenAmount = children->size();

		for (i = 0; i < childrenAmount; ++i)
		{
			renderComponents(children->at(i), activeShader, DELTA_TIME);
		}
	}

	const Mesh *CURRENT_MESH = node->mMESH;

	if (CURRENT_MESH != nullptr)
	{
		glm::mat4x4 componentSpace = MatrixUtil::createTransform(node->mMeshTransform);
		glm::mat4x4 modelSpace = MatrixUtil::createTransform(node)
		activeShader.loadMat4("transformMatrix", GL_FALSE, glm::value_ptr(glm::mat4x4()));
		CURRENT_MESH->render(DELTA_TIME);
	}
}*/

///////////////////////////////////
////////// ComponentNode //////////
///////////////////////////////////

Model::ComponentNode::ComponentNode(const Mesh *MESH, ComponentNode *parent) :
	mMESH(MESH), //Reference to static mesh somewhere else or nullptr.
	mParentComponent(parent), //Reference to parent component or null if no parent
	mMeshTransform(new Transform())
{

}

Model::ComponentNode::~ComponentNode()
{
	delete mMeshTransform;
}

void Model::ComponentNode::render(const GLdouble &alpha, const glm::mat4x4& modelTransform, const ShaderProgram &activeShader)
{
	mMeshTransform->lerp(alpha);

	glm::mat4x4 parentTransform;
	if (mParentComponent != nullptr)
	{
		Transform *parent = mParentComponent->mMeshTransform;
		//parent->lerp(alpha);
		parentTransform = parent->getTransformationMat();
	}
	
	glm::mat4x4 modelSpace = modelTransform * parentTransform* mMeshTransform->getTransformationMat();
	
	//BBLogger::logDebug("Model.cpp", "MODEL TRANSFORM: " + MatrixUtil::to_string(modelTransform), Logger::EnumLogLocation::CONSOLE);
	
	activeShader.loadMat4("transformMatrix", GL_FALSE, glm::value_ptr(modelSpace));
	mMESH->render(alpha);
}

void Model::update(const GLdouble &deltaTime)
{
	mModelTransform->update();
}

void Model::lerpPosition(const GLdouble &alpha)
{
	mModelTransform->lerp(alpha);
}

const TextureWrapper* Model::getTextureWrapper() const
{
	return mTextureWrapper;
}