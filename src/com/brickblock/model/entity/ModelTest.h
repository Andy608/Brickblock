#ifndef BB_MODELTEST_H_
#define BB_MODELTEST_H_

#include "EntityModel.h"

namespace bb
{
	class ModelTest : public EntityModel
	{
	public:
		ModelTest();
		~ModelTest();

		void update(const GLdouble &deltaTime);

		void render(const GLdouble &deltaTime);

	private:
		ComponentNode *mTest;
		ComponentNode *mOrbit;

		ComponentNode *mLightSource;
	};
}

#endif