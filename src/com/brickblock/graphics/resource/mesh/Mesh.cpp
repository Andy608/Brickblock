#include "Mesh.h"
#include "util/VAOWrapper.h"
#include "util/EBOWrapper.h"
#include "../../../util/filesystem/file/FileLocation.h"
#include "../../../util/filesystem/file/reader/StringFileReader.h"
#include "../../../util/filesystem/StringUtil.h"
#include "../../../util/logger/BBLogger.h"

using namespace bb;

const std::string Mesh::CLASS_NAME = "Mesh.cpp";

const char Mesh::SPACE_DELIMITER = ' ';
const char Mesh::SLASH_DELIMITER = '/';

const std::string Mesh::VERTEX_DELIMITER = "v ";
const std::string Mesh::VERTEX_TEX_COORD_DELIMITER = "vt";
const std::string Mesh::VERTEX_NORMAL_DELIMITER = "vn";
const std::string Mesh::FACE_DELIMITER = "f ";

const GLuint Mesh::INDEX_DELIMITER_START = 0;
const GLuint Mesh::INDEX_DELIMITER_END = 2;

Mesh::Mesh(FileLocation *meshFileLocation) :
	Resource(),
	mMeshFileLocation(meshFileLocation),
	mVAOWrapper(nullptr),
	mVBOWrappers(new std::vector<VBOWrapper*>()),
	mEBOWrapper(nullptr),
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
	delete mMeshFileLocation;
}

void Mesh::load()
{
	if (mIsLoaded)
	{
		//Log saying model is already loaded.
		BBLogger::logWarn(CLASS_NAME, "This mesh is already loaded.");
		return;
	}

	std::vector<std::string> modelInformation;
	StringFileReader::getInstance().getContentsByLine(*mMeshFileLocation, modelInformation);

	if (modelInformation.size() > 0)
	{
		std::vector<GLfloat> unorderedPositions;
		std::vector<GLfloat> unorderedTexCoords;
		std::vector<GLfloat> unorderedNormals;
		GLuint modelFaceStartLine = 0;

		//log debug saying amount of file lines
		BBLogger::logDebug(CLASS_NAME, "Lines in file: " + std::to_string(modelInformation.size()));

		GLuint lineIndex;
		std::string currentLine;
		std::string typeDelimiter;
		for (lineIndex = 0; lineIndex < modelInformation.size(); ++lineIndex)
		{
			currentLine = modelInformation.at(lineIndex);
			typeDelimiter = currentLine.substr(INDEX_DELIMITER_START, INDEX_DELIMITER_END);

			if (typeDelimiter.compare(VERTEX_DELIMITER) == 0)
			{
				addFloatsFromString(currentLine.substr(VERTEX_DELIMITER.size()), unorderedPositions, VERTEX_DELIMITER.size(), SPACE_DELIMITER);
			}
			else if (typeDelimiter.compare(VERTEX_TEX_COORD_DELIMITER) == 0)
			{
				addFloatsFromString(currentLine.substr(VERTEX_TEX_COORD_DELIMITER.size() + 1), unorderedTexCoords, VERTEX_TEX_COORD_DELIMITER.size() + 1, SPACE_DELIMITER);
			}
			else if (typeDelimiter.compare(VERTEX_NORMAL_DELIMITER) == 0)
			{
				addFloatsFromString(currentLine.substr(VERTEX_NORMAL_DELIMITER.size() + 1), unorderedNormals, VERTEX_NORMAL_DELIMITER.size() + 1, SPACE_DELIMITER);
			}
			else if (typeDelimiter.compare(FACE_DELIMITER) == 0)
			{
				modelFaceStartLine = lineIndex;
				break;
			}
		}

		std::vector<GLint> indices;
		std::vector<GLfloat> sortedTexCoords = std::vector<GLfloat>(unorderedTexCoords.size());
		std::vector<GLfloat> sortedNormals = std::vector<GLfloat>(unorderedNormals.size());

		std::vector<std::string> facesString;
		std::vector<GLint> posTexAndNormal;

		//Read each line until the end of the file
		for (lineIndex = modelFaceStartLine; lineIndex < modelInformation.size(); ++lineIndex)
		{
			currentLine = modelInformation.at(lineIndex).substr(FACE_DELIMITER.size());
			StringUtil::split(currentLine.c_str(), SPACE_DELIMITER, GL_FALSE, facesString);
			BBLogger::logWarn(CLASS_NAME, "CurrentLine: " + currentLine);

			//Read each face info
			GLuint strIndex;
			GLuint offset;
			for (strIndex = 0; strIndex < facesString.size(); ++strIndex)
			{
				BBLogger::logWarn(CLASS_NAME, "Face info [" + std::to_string(strIndex) + "]: " + facesString.at(strIndex));
				
				getIntsFromString(facesString.at(strIndex), posTexAndNormal, 0, SLASH_DELIMITER);
				BBLogger::logTrace(CLASS_NAME, "PosTexAndNormal: " 
					+ std::to_string(posTexAndNormal[0]) 
					+ std::to_string(posTexAndNormal[1]));

				indices.push_back(posTexAndNormal[0]);
				offset = 1;

				if (!unorderedTexCoords.empty())
				{
					sortedTexCoords.push_back(unorderedTexCoords.at((posTexAndNormal[offset] - 1) * 2));
					sortedTexCoords.push_back(unorderedTexCoords.at((posTexAndNormal[offset] - 1) * 2 + 1));
					++offset;
				}

				if (!unorderedNormals.empty())
				{
					sortedNormals.push_back(unorderedNormals.at((posTexAndNormal[offset] - 1) * 3));
					sortedNormals.push_back(unorderedNormals.at((posTexAndNormal[offset] - 1) * 3 + 1));
					sortedNormals.push_back(unorderedNormals.at((posTexAndNormal[offset] - 1) * 3 + 2));
				}

				posTexAndNormal.clear();
			}

			facesString.clear();
		}

		if (!unorderedPositions.empty())
		{
			addBufferData(new VBOWrapper(VBOWrapper::BufferType::POSITION, unorderedPositions, 3));
		}

		if (!sortedTexCoords.empty())
		{
			addBufferData(new VBOWrapper(VBOWrapper::BufferType::TEX_COORDS, sortedTexCoords, 2));
		}

		if (!sortedNormals.empty())
		{
			addBufferData(new VBOWrapper(VBOWrapper::BufferType::NORMALS, sortedNormals, 3));
		}

		if (indices.size() > 0)
		{
			setElementBuffer(new EBOWrapper(indices));
		}

		mVAOWrapper = new VAOWrapper();

		prepareMesh();
		mIsLoaded = GL_TRUE;
	}
	else
	{
		//Log saying file was empty.
		BBLogger::logWarn(CLASS_NAME, "The file was empty.");
	}
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

void Mesh::render(const GLdouble& DELTA_TIME)
{
	//Change this in the future to support multiple rendering types.

	mVAOWrapper->bind();
	glDrawArrays(GL_TRIANGLES, 0, mEBOWrapper->getIndiceCount() * 3);
	//glDrawElements(GL_TRIANGLES, mEBOWrapper->getIndiceCount(), GL_UNSIGNED_INT, 0);
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

	//mEBOWrapper->unbind();

	mVAOWrapper->unbind();
}

void Mesh::addBufferData(VBOWrapper* newBufferData)
{
	mVBOWrappers->push_back(newBufferData);
}

void Mesh::addFloatsFromString(std::string line, std::vector<GLfloat>& data, GLuint beginIndex, const char DELIMITER)
{
	//GLuint endIndex;
	GLfloat extractedFloat;

	std::vector<std::string> floats;
	StringUtil::split(line.c_str(), DELIMITER, GL_FALSE, floats);

	GLuint i;
	for (i = 0; i < floats.size(); ++i)
	{
		BBLogger::logWarn(CLASS_NAME, "Floats on line: " + line + " | Floats at i: " + floats.at(i));
		extractedFloat = std::stof(floats.at(i));
		data.push_back(extractedFloat);
	}
	
	/*for (floatsToAddIndex = 0; floatsToAddIndex < amountOfFloats; ++floatsToAddIndex)
	{
		endIndex = line.substr(beginIndex).find_first_of(DELIMITER) + beginIndex;
		extractedFloat = std::stof(line.substr(beginIndex, endIndex - beginIndex));
		data.push_back(extractedFloat);
		beginIndex = endIndex + 1;
	}*/
}

void Mesh::getIntsFromString(std::string line, std::vector<GLint>& data, GLuint beginIndex, const char DELIMITER)
{
	//GLuint endIndex;
	GLint extractedFloat;

	std::vector<std::string> ints;
	StringUtil::split(line.c_str(), DELIMITER, GL_FALSE, ints);

	GLuint i;
	for (i = 0; i < ints.size(); ++i)
	{
		BBLogger::logTrace(CLASS_NAME, ints.at(i));
	}

	for (i = 0; i < ints.size(); ++i)
	{
		extractedFloat = std::stoi(ints.at(i));
		data.push_back(extractedFloat);
	}
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