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

const GLuint Mesh::FACE_AMOUNT = 3;

Mesh::Mesh(const FileLocation& MESH_FILE_LOCATION) :
	Resource(),
	mMESH_FILE_LOCATION(MESH_FILE_LOCATION),
	mVAOWrapper(nullptr),
	mVBOWrappers(new std::vector<VBOWrapper*>()),
	mEBOWrapper(nullptr)
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

void Mesh::load()
{
	if (mIsLoaded)
	{
		//Log saying model is already loaded.
		BBLogger::getLogger().logWarn(CLASS_NAME, "This mesh is already loaded.", Logger::EnumLogLocation::CONSOLE_AND_FILE);
		return;
	}

	std::vector<std::string> modelInformation;
	StringFileReader::getInstance().getContentsByLine(mMESH_FILE_LOCATION, modelInformation);

	if (modelInformation.size() > 0)
	{
		std::vector<GLfloat> unorderedPositions;
		std::vector<GLfloat> unorderedTexCoords;
		std::vector<GLfloat> unorderedNormals;
		GLuint modelFaceStartLine = 0;

		//log debug saying amount of file lines
		BBLogger::getLogger().logDebug(CLASS_NAME, "Lines in file: " + modelInformation.size(), Logger::EnumLogLocation::CONSOLE_AND_FILE);

		GLuint lineIndex;
		std::string currentLine;
		std::string typeDelimiter;
		for (lineIndex = 0; lineIndex < modelInformation.size(); ++lineIndex)
		{
			currentLine = modelInformation.at(lineIndex);
			typeDelimiter = currentLine.substr(INDEX_DELIMITER_START, INDEX_DELIMITER_END);

			if (typeDelimiter.compare(VERTEX_DELIMITER) == 0)
			{
				addFloatsFromString(currentLine, unorderedPositions, VERTEX_DELIMITER.size(), 3, SPACE_DELIMITER);
			}
			else if (typeDelimiter.compare(VERTEX_TEX_COORD_DELIMITER) == 0)
			{
				addFloatsFromString(currentLine, unorderedTexCoords, VERTEX_TEX_COORD_DELIMITER.size() + 1, 2, SPACE_DELIMITER);
			}
			else if (typeDelimiter.compare(VERTEX_NORMAL_DELIMITER) == 0)
			{
				addFloatsFromString(currentLine, unorderedNormals, VERTEX_NORMAL_DELIMITER.size() + 1, 3, SPACE_DELIMITER);
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
		std::vector<GLint> faces;

		for (lineIndex = modelFaceStartLine; lineIndex < modelInformation.size(); ++lineIndex)
		{
			currentLine = modelInformation.at(lineIndex).substr(FACE_DELIMITER.size());
			StringUtil::split(currentLine.c_str(), SLASH_DELIMITER, facesString);

			GLuint strIndex;
			for (strIndex = 0; strIndex < facesString.size(); ++strIndex)
			{
				getIntsFromString(facesString.at(strIndex), faces, 0, FACE_AMOUNT, SLASH_DELIMITER);

				indices.push_back(faces[0]);

				sortedTexCoords.push_back(unorderedTexCoords.at(faces[1] * 2));
				sortedTexCoords.push_back(unorderedTexCoords.at(faces[1] * 2 + 1));

				sortedNormals.push_back(unorderedNormals.at(faces[2] * 3));
				sortedNormals.push_back(unorderedNormals.at(faces[2] * 3 + 1));
				sortedNormals.push_back(unorderedNormals.at(faces[2] * 3 + 2));

				faces.clear();
			}

			facesString.clear();
		}

		if (unorderedPositions.size() > 0)
		{
			addBufferData(new VBOWrapper(VBOWrapper::BufferType::POSITION, unorderedPositions, 3));
		}

		if (sortedTexCoords.size() > 0)
		{
			addBufferData(new VBOWrapper(VBOWrapper::BufferType::TEX_COORDS, sortedTexCoords, 2));
		}

		if (sortedNormals.size() > 0)
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
		BBLogger::getLogger().logWarn(CLASS_NAME, "The file was empty.", Logger::EnumLogLocation::CONSOLE_AND_FILE);
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
	BBLogger::getLogger().logWarn(CLASS_NAME, "This model does not support that buffer type.", Logger::EnumLogLocation::CONSOLE_AND_FILE);

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

void Mesh::addFloatsFromString(std::string line, std::vector<GLfloat>& data, GLuint beginIndex, GLuint amountOfFloats, const char DELIMITER)
{
	//GLuint endIndex;
	GLfloat extractedFloat;

	std::vector<std::string> floats;
	StringUtil::split(line.c_str(), DELIMITER, floats);

	GLuint i;
	for (i = 0; i < floats.size(); ++i)
	{
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

void Mesh::getIntsFromString(std::string line, std::vector<GLint>& data, GLuint beginIndex, GLuint amountOfInts, const char DELIMITER)
{
	//GLuint endIndex;
	GLint extractedFloat;

	std::vector<std::string> ints;
	StringUtil::split(line.c_str(), DELIMITER, ints);

	GLuint i;
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