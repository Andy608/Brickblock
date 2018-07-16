#ifndef BB_GLOBJECTWRAPPER_H_
#define BB_GLOBJECTWRAPPER_H_

#include <glad/glad.h>

namespace bb
{
	struct GLObjectWrapper
	{
	public:
		GLObjectWrapper();
		virtual ~GLObjectWrapper();

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		const GLuint& getID() const;

	protected:
		static const GLuint SIZE;
		GLuint mID;

		virtual void createID() = 0;
	};
}

#endif