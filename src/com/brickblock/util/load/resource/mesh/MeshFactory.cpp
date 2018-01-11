#include "MeshFactory.h"
#include "../../../../util/filesystem/StringUtil.h"
#include "../../../../util/filesystem/file/reader/StringFileReader.h"
#include "../../../../util/logger/BBLogger.h"
#include "util/VAOWrapper.h"
#include "util/VBOWrapper.h"
#include "util/EBOWrapper.h"
#include "util/Vertex.h"
using namespace bb;

const char MeshFactory::SPACE_DELIMITER = ' ';
const char MeshFactory::SLASH_DELIMITER = '/';

const std::string MeshFactory::VERTEX_DELIMITER = "v ";
const std::string MeshFactory::VERTEX_TEX_COORD_DELIMITER = "vt";
const std::string MeshFactory::VERTEX_NORMAL_DELIMITER = "vn";
const std::string MeshFactory::FACE_DELIMITER = "f ";

const GLuint MeshFactory::INDEX_DELIMITER_START = 0;
const GLuint MeshFactory::INDEX_DELIMITER_END = 2;

void MeshFactory::loadMeshDataFromFile(Mesh& mesh, FileLocation *meshFileLocation)
{
	if (!meshFileLocation)
	{
		BBLogger::logError("MeshFactory.cpp", "The file location is null. Cannot create mesh from null file location.");
		return;
	}
	else if (!meshFileLocation->isExist())
	{
		BBLogger::logError("MeshFactory.cpp", "The file location: \'" + meshFileLocation->getPath() + "\' does not exist.");
		return;
	}

	std::vector<std::string> lineInfo;
	StringFileReader::getInstance().getContentsByLine(*meshFileLocation, lineInfo);

	if (lineInfo.size() > 0)
	{
		std::vector<GLfloat> unorderedPositions;
		std::vector<GLfloat> unorderedTexCoords;
		std::vector<GLfloat> unorderedNormals;
		GLuint modelFaceStartLine = 0;

		GLuint lineIndex;
		std::string currentLine;
		std::string typeDelimiter;
		for (lineIndex = 0; lineIndex < lineInfo.size(); ++lineIndex)
		{
			currentLine = lineInfo.at(lineIndex);
			typeDelimiter = currentLine.substr(INDEX_DELIMITER_START, INDEX_DELIMITER_END);

			if (typeDelimiter.compare(VERTEX_DELIMITER) == 0)
			{
				addFloatsFromString(currentLine.substr(VERTEX_DELIMITER.size()),
					unorderedPositions, VERTEX_DELIMITER.size(), SPACE_DELIMITER);
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

		std::vector<std::string> facesAsStrings;
		std::vector<GLint> faceInformation;

		std::vector<Vertex> vertices;
		std::vector<GLint> indices;

		//For each line that is a face
		for (lineIndex = modelFaceStartLine; lineIndex < lineInfo.size(); ++lineIndex)
		{
			currentLine = lineInfo.at(lineIndex).substr(FACE_DELIMITER.size());

			//FacesAsStrings should be 3 in length = 1/1/1 1/1/1 1/1/1
			StringUtil::split(currentLine.c_str(), SPACE_DELIMITER, GL_FALSE, facesAsStrings);

			//Read each face info
			GLuint strIndex;
			for (strIndex = 0; strIndex < facesAsStrings.size(); ++strIndex)
			{
				//adds face info to list
				getIntsFromString(facesAsStrings.at(strIndex), faceInformation, 0, SLASH_DELIMITER);

				Vertex potentialVertex = Vertex(faceInformation[0], faceInformation[1], faceInformation[2]);
				
				GLboolean found = GL_FALSE;

				GLuint i;

				for (i = 0; i < vertices.size(); ++i)
				{
					Vertex &vertInList = vertices.at(i);

					//NOT UNIQUE INDEX
					if (vertInList == potentialVertex)
					{
						//Set the indice to the index of the vertex in the list
						indices.push_back(i);
						found = GL_TRUE;
						break;
					}
				}

				if (!found)
				{
					//Add unique vertex to list.
					vertices.push_back(potentialVertex);

					//Set the indice to the index of the new vertex in the list.
					indices.push_back(vertices.size() - 1);
				}

				faceInformation.clear();
			}

			facesAsStrings.clear();
		}

		std::vector<GLfloat> sortedPositions;
		std::vector<GLfloat> sortedTexCoords;
		std::vector<GLfloat> sortedNormals;

		GLuint i = 0;
		for (i = 0; i < vertices.size(); ++i)
		{
			Vertex currentVertex = vertices.at(i);

			sortedPositions.push_back(unorderedPositions.at(currentVertex.mPositionIndex * 3));
			sortedPositions.push_back(unorderedPositions.at(currentVertex.mPositionIndex * 3 + 1));
			sortedPositions.push_back(unorderedPositions.at(currentVertex.mPositionIndex * 3 + 2));

			if (!unorderedTexCoords.empty())
			{
				sortedTexCoords.push_back(unorderedTexCoords.at(currentVertex.mTextureIndex * 2));
				sortedTexCoords.push_back(1.0f - unorderedTexCoords.at(currentVertex.mTextureIndex * 2 + 1));
			}

			if (!unorderedNormals.empty())
			{
				sortedNormals.push_back(unorderedNormals.at(currentVertex.mNormalIndex * 3));
				sortedNormals.push_back(unorderedNormals.at(currentVertex.mNormalIndex * 3 + 1));
				sortedNormals.push_back(unorderedNormals.at(currentVertex.mNormalIndex * 3 + 2));
			}
		}

		mesh.addBufferData(new VBOWrapper(VBOWrapper::BufferType::POSITION, sortedPositions, 3));
	
		if (!sortedTexCoords.empty())
			mesh.addBufferData(new VBOWrapper(VBOWrapper::BufferType::TEX_COORDS, sortedTexCoords, 2));
		
		if (!sortedNormals.empty())
			mesh.addBufferData(new VBOWrapper(VBOWrapper::BufferType::NORMALS, sortedNormals, 3));
		
		mesh.setElementBuffer(new EBOWrapper(indices));

		mesh.mVAOWrapper = new VAOWrapper();

		mesh.prepareMesh();
		mesh.mIsLoaded = GL_TRUE;

		/*for each face
		for each vertex in face
		key = fn(position_index, normal_index, texcoord_index)
		if vertices.find(key)
		new_index = vertex(key).index
		else
		create vertex from position / normal / texcorrd
		store new vertex in vertices with key and next_vertex
		new_index = next_vertex
		increment next_index
		end
		save new_index in index buffer
		loop*/
	}
	else
	{
		BBLogger::logWarn("MeshFactory.cpp", "The file: " + meshFileLocation->getPath() + " was empty.");
	}
}

void MeshFactory::addFloatsFromString(std::string line, std::vector<GLfloat>& data, GLuint beginIndex, const char DELIMITER)
{
	//GLuint endIndex;
	GLfloat extractedFloat;

	std::vector<std::string> floats = StringUtil::split(line.c_str(), DELIMITER, GL_FALSE);

	GLuint i;
	for (i = 0; i < floats.size(); ++i)
	{
		//BBLogger::logWarn(CLASS_NAME, "Floats on line: " + line + " | Floats at i: " + floats.at(i));
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

void MeshFactory::getIntsFromString(std::string line, std::vector<GLint>& data, GLuint beginIndex, const char DELIMITER)
{
	//GLuint endIndex;
	GLint extractedInt;

	std::vector<std::string> ints = StringUtil::split(line.c_str(), DELIMITER, GL_TRUE);

	/*GLuint i;
	for (i = 0; i < ints.size(); ++i)
	{
	BBLogger::logTrace(CLASS_NAME, ints.at(i));
	}*/

	GLuint i;
	for (i = 0; i < ints.size(); ++i)
	{
		if (ints.at(i) == " ")
		{
			extractedInt = -1;
		}
		else
		{
			extractedInt = std::stoi(ints.at(i)) - 1;
		}
		
		data.push_back(extractedInt);
	}
}