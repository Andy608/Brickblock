#ifndef BB_EBOWRAPPER_H_
#define BB_EBOWRAPPER_H_

#include "GLObjectWrapper.h"

namespace bb
{
	struct EBOWrapper : public GLObjectWrapper
	{
	public:
		EBOWrapper(std::vector<GLint> indices);
		~EBOWrapper();

		virtual void bind() const;
		virtual void unbind() const;

		const GLuint getIndiceCount() const;
		const std::vector<GLint> getIndices() const;

	private:
		std::vector<GLint> mIndiceList;

		virtual void createID();

	};
}

#endif