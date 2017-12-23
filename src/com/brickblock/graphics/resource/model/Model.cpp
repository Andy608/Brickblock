#include "Model.h"
#include "../../../util/math/physics/Transform.h"
#include "Mesh.h"
using namespace bb;

Model::Model() :
	mRoot(nullptr),
	mModelTransform(new Transform())
{

}

Model::~Model()
{
	//unload();

	if (mRoot != nullptr)
	{
		delete mRoot;
	}

	delete mModelTransform;
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

void Model::render(const GLdouble& DELTA_TIME)
{
	renderComponents(mRoot, DELTA_TIME);
}

void Model::renderComponents(ComponentNode *node, const GLdouble& DELTA_TIME)
{
	std::vector<ComponentNode*> *children = mRoot->mChildNodes;

	if (children != nullptr)
	{
		GLuint i;
		GLuint childrenAmount = children->size();

		for (i = 0; i < childrenAmount; ++i)
		{
			renderComponents(children->at(i), DELTA_TIME);
		}
	}

	Mesh *currentMesh = mRoot->mMesh;

	if (currentMesh != nullptr)
	{
		currentMesh->render(DELTA_TIME);
	}
}

///////////////////////////////////
////////// ComponentNode //////////
///////////////////////////////////

Model::ComponentNode::ComponentNode(GLuint id, Mesh *mesh) :
	mComponentID(id),
	mMesh(mesh), //Reference to static mesh somewhere else or nullptr.
	mChildNodes(new std::vector<ComponentNode*>()),
	mMeshTransform(new Transform())
{

}

Model::ComponentNode::~ComponentNode()
{
	clearComponents();
	delete mMeshTransform;
	delete mChildNodes;
}

void Model::ComponentNode::addChild(ComponentNode *node)
{
	mChildNodes->push_back(node);
}

void Model::ComponentNode::clearComponents()
{
	GLuint i;
	for (i = 0; i < mChildNodes->size(); ++i)
	{
		ComponentNode *node = mChildNodes->at(i);
		if (node != nullptr)
		{
			node->clearComponents();
			delete node;
		}
	}

	mChildNodes->clear();
}

void Model::ComponentNode::removeChild(GLuint componentID)
{
	GLuint i;
	for (i = 0; i < mChildNodes->size(); ++i)
	{
		ComponentNode *node = mChildNodes->at(i);
		if (node != nullptr)
		{
			if (node->mComponentID == componentID)
			{
				node->clearComponents();
				delete node;
				mChildNodes->erase(mChildNodes->begin() + i);
				return;
			}
			else
			{
				node->removeChild(componentID);
			}
		}
	}
}

const GLuint& Model::ComponentNode::getComponentID() const
{
	return mComponentID;
}