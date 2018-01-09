#include "Mesh.h"
#include "util/VAOWrapper.h"
#include "util/EBOWrapper.h"
#include "../../../../util/logger/BBLogger.h"
#include "../shader/ShaderProgram.h"
#include "MeshFactory.h"
#include "../../../../util/filesystem/StringUtil.h"
#include "../../../../util/filesystem/file/reader/StringFileReader.h"
#include "util\Vertex.h"

using namespace bb;

const std::string Mesh::CLASS_NAME = "Mesh.cpp";

Mesh::Mesh(std::string resourceID, const FileLocation &meshDataLocation) :
	Resource(resourceID, Resource::ResourceType::MESH),
	mVAOWrapper(nullptr),
	mVBOWrappers(new std::vector<VBOWrapper*>()),
	mEBOWrapper(nullptr),
	mMeshDataLocation(meshDataLocation),
	mColor(glm::vec4(1.0)) // White overlay by default as to not affect textures.
{
	
}

Mesh::~Mesh()
{
	if (mIsLoaded)
	{
		unload();
	}

	delete mVBOWrappers;
}

const Mesh& Mesh::operator=(const Mesh& another)
{
	return another;
}

void Mesh::load()
{
	if (mIsLoaded)
	{
		BBLogger::logWarn(CLASS_NAME, "This mesh is already loaded.");
		return;
	}

	MeshFactory::loadMeshDataFromFile(*this, mMeshDataLocation);
}

void Mesh::unload()
{
	clearBufferData();

	if (mEBOWrapper != nullptr)
	{
		delete mEBOWrapper;
	}

	if (mVAOWrapper != nullptr)
	{
		delete mVAOWrapper;
	}

	mIsLoaded = GL_FALSE;
}

VAOWrapper* const Mesh::getVAOWrapper() const
{
	return mVAOWrapper;
}

VBOWrapper* const Mesh::getVBOWrapper(const VBOWrapper::BufferType& BUFFER_TYPE) const
{
	GLuint i;
	for (i = 0; i < mVBOWrappers->size(); ++i)
	{
		VBOWrapper *currentWrapper = mVBOWrappers->at(i);
		if (currentWrapper->mBUFFER_TYPE == BUFFER_TYPE)
		{
			return currentWrapper;
		}
	}

	//Log this model does not support that buffer type.
	BBLogger::logWarn(CLASS_NAME, "This model does not support that buffer type.");

	return nullptr;
}

EBOWrapper* const Mesh::getEBOWrapper() const
{
	return mEBOWrapper;
}

void Mesh::render(const GLdouble& deltaTime) const
{
	//Change this in the future to support multiple rendering types.

	//BBLogger::logDebug(CLASS_NAME, std::to_string(mEBOWrapper->getIndiceCount()));

	mVAOWrapper->bind();
	mEBOWrapper->bind();
	//glDrawArrays(GL_TRIANGLES, 0, getVBOWrapper(VBOWrapper::BufferType::POSITION)->getVertexCount());
	glDrawElements(GL_TRIANGLES, mEBOWrapper->getIndiceCount(), GL_UNSIGNED_INT, 0);
	mEBOWrapper->unbind();
	mVAOWrapper->unbind();
}

void Mesh::prepareMesh()
{
	mVAOWrapper->bind();

	mEBOWrapper->bind();

	GLuint i;
	for (i = 0; i < mVBOWrappers->size(); ++i)
	{
		VBOWrapper *currentWrapper = mVBOWrappers->at(i);
		currentWrapper->bind();
		mVAOWrapper->bindVBOToVAO(i, *currentWrapper);
		currentWrapper->unbind();
	}

	mEBOWrapper->unbind();

	mVAOWrapper->unbind();
}

void Mesh::addBufferData(VBOWrapper* newBufferData)
{
	mVBOWrappers->push_back(newBufferData);
}

void Mesh::setElementBuffer(EBOWrapper *newWrapper)
{
	mEBOWrapper = newWrapper;
}

void Mesh::clearBufferData()
{
	GLuint i;
	for (i = 0; i < mVBOWrappers->size(); ++i)
	{
		VBOWrapper *currentWrapper = mVBOWrappers->at(i);
		if (currentWrapper != nullptr)
		{
			delete currentWrapper;
		}
	}

	mVBOWrappers->clear();
}