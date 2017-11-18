#ifndef RESOURCE_H_
#define RESOURCE_H_

#include <glad\glad.h>

namespace bb
{
	class Resource
	{
	public:
		Resource();
		virtual ~Resource();

		virtual void load() = 0;
		virtual void unload() = 0;

		GLboolean isLoaded() const;

	protected:
		GLboolean mIsLoaded;
	};
}

#endif