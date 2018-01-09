#ifndef BB_VBOWRAPPER_H_
#define BB_VBOWRAPPER_H_

#include "GLObjectWrapper.h"
#include <vector>

namespace bb
{
	struct VBOWrapper : public GLObjectWrapper
	{
	public:
		enum class BufferType : const GLuint
		{
			POSITION,
			/*COLORS,*/ // Color will be a uniform passed into the brick shader.
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
		std::vector<GLfloat> mBufferData;
		GLuint mVertexCount;

		virtual void createID();
	};
}

#endif