#ifndef BB_VBOWRAPPER_H_
#define BB_VBOWRAPPER_H_

#include "GLObjectWrapper.h"

namespace bb
{
	struct VBOWrapper : public GLObjectWrapper
	{
	public:
		enum class BufferType : const GLuint
		{
			POSITION,
			COLORS,
			TEX_COORDS,
			NORMALS
		};

		const BufferType mBUFFER_TYPE;

		VBOWrapper(const BufferType& BUFFER_TYPE, std::vector<GLfloat> buffer, GLuint elementsPerVertex);
		~VBOWrapper();

		virtual void bind() const;
		virtual void unbind() const;

		const GLuint& getElementsPerVertex() const;
		const GLuint& getVertexCount() const;
		const std::vector<GLfloat>& getBufferData() const;

	private:
		GLuint mElementsPerVertex;
		GLuint mVertexCount;
		std::vector<GLfloat> mBufferData;

		virtual void createID();
	};
}

#endif