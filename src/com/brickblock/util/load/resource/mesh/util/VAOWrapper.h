#ifndef BB_VAOWRAPPER_H_
#define BB_VAOWRAPPER_H_

#include "GLObjectWrapper.h"

namespace bb
{
	struct VBOWrapper;
	struct VAOWrapper : public GLObjectWrapper
	{
	public:
		VAOWrapper();
		~VAOWrapper();

		virtual void bind() const;
		virtual void unbind() const;

		void bindVBOToVAO(GLuint bufferIndex, VBOWrapper& bufferData);

	private:

		virtual void createID();
	};
}

#endif