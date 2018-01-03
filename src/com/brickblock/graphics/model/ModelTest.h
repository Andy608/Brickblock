#ifndef BB_MODELTEST_H_
#define BB_MODELTEST_H_

#include "Model.h"

namespace bb
{
	class ModelTest : public Model
	{
	public:
		ModelTest();

		void update(const GLdouble& DELTA_TIME);
	};
}

#endif