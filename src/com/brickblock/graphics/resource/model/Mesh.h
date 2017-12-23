#ifndef BB_MESH_H_
#define BB_MESH_H_

#include "../Resource.h"
#include "util/VBOWrapper.h"
#include <string>

namespace bb
{
	class FileLocation;
	struct VAOWrapper;
	struct EBOWrapper;

	class Mesh : public Resource
	{
	public:
		//Load mesh from file. (Make another constructor in the future to load not from file --subclass loading).
		Mesh(const FileLocation& MESH_FILE_LOCATION);
		virtual ~Mesh();

		virtual void load();
		virtual void unload();

		VAOWrapper* const getVAOWrapper() const;
		VBOWrapper* const getVBOWrapper(const VBOWrapper::BufferType& BUFFER_TYPE) const;
		EBOWrapper* const getEBOWrapper() const;

		virtual void render(const GLdouble& DELTA_TIME);

	private:
		static const std::string CLASS_NAME;
		static const char SPACE_DELIMITER;
		static const char SLASH_DELIMITER;

		static const std::string VERTEX_DELIMITER;
		static const std::string VERTEX_TEX_COORD_DELIMITER;
		static const std::string VERTEX_NORMAL_DELIMITER;
		static const std::string FACE_DELIMITER;

		static const GLuint INDEX_DELIMITER_START;
		static const GLuint INDEX_DELIMITER_END;

		static const GLuint FACE_AMOUNT;

		const FileLocation& mMESH_FILE_LOCATION;

		VAOWrapper *mVAOWrapper;
		std::vector<VBOWrapper*>* mVBOWrappers;
		EBOWrapper *mEBOWrapper;

		virtual void prepareMesh();
		
		void setElementBuffer(EBOWrapper *newWrapper);
		void addBufferData(VBOWrapper* newBufferData);

		void addFloatsFromString(std::string line, std::vector<GLfloat>& data, GLuint beginIndex, GLuint amountOfFloats, const char DELIMITER);
		void getIntsFromString(std::string line, std::vector<GLint>& data, GLuint beginIndex, GLuint amountOfInts, const char DELIMITER);
	
		void clearBufferData();
	};
}

#endif