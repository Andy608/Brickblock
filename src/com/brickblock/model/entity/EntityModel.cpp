#include "EntityModel.h"
#include "../../util/math/MatrixUtil.h"
#include "../../util/logger/BBLogger.h"
#include "../../util/load/resource/mesh/Mesh.h"
#include "../../util/math/physics/Transform.h"
#include "../../util/load/resource/mesh/util/TextureWrapper.h"
#include <glm/gtc/type_ptr.hpp>
using namespace bb;

EntityModel::EntityModel() :
	mModelTransform(new Transform()),
	mTextureWrapper(nullptr)
{

}

EntityModel::~EntityModel()
{
	delete mModelTransform;

	if (mTextureWrapper != nullptr)
	{
		delete mTextureWrapper;
	}
}

///////////////////////////////////
////////// ComponentNode //////////
///////////////////////////////////

EntityModel::ComponentNode::ComponentNode(const Mesh *MESH, ComponentNode *parent) :
	mMESH(MESH), //Reference to static mesh somewhere else or nullptr.
	mParentComponent(parent), //Reference to parent component or null if no parent
	mMeshTransform(new Transform())
{

}

EntityModel::ComponentNode::~ComponentNode()
{
	delete mMeshTransform;
}

void EntityModel::ComponentNode::render(const GLdouble &alpha, const glm::mat4x4& modelTransform, const ShaderProgram &activeShader)
{
	mMeshTransform->lerp(alpha);

	glm::mat4x4 parentTransform;
	if (mParentComponent)
	{
		Transform *parent = mParentComponent->mMeshTransform;
		parent->lerp(alpha);
		parentTransform = parent->getTransformationMat();
	}
	
	glm::mat4x4 modelSpace = modelTransform * parentTransform* mMeshTransform->getTransformationMat();
	
	//BBLogger::logDebug("Model.cpp", "MODEL TRANSFORM: " + MatrixUtil::to_string(modelTransform), Logger::EnumLogLocation::CONSOLE);
	
	activeShader.loadMat4("transformMatrix", GL_FALSE, glm::value_ptr(modelSpace));
	mMESH->render(alpha);
}

void EntityModel::update(const GLdouble &deltaTime)
{
	mModelTransform->update();
}

void EntityModel::lerpPosition(const GLdouble &alpha)
{
	mModelTransform->lerp(alpha);
}

const TextureWrapper* EntityModel::getTextureWrapper() const
{
	return mTextureWrapper;
}