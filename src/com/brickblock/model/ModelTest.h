#ifndef BB_MODELTEST_H_
#define BB_MODELTEST_H_

#include "Model.h"

namespace bb
{
	class ModelTest : public Model
	{
	public:
		ModelTest();
		~ModelTest();

		void update(const GLdouble &deltaTime);

		void render(const GLdouble &deltaTime, const ShaderProgram &activeShader);

	private:
		ComponentNode *mTest;
		ComponentNode *mOrbit;
	};
}

#endif