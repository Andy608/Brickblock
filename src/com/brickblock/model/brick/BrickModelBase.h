#ifndef BB_BRICKMODELBASE_H_
#define BB_BRICKMODELBASE_H_

#include <string>
#include <glad/glad.h>
#include "../../brick/BrickInfo.h"
#include "../../util/load/resource/mesh/Mesh.h"

namespace bb
{
	class BrickModelBase
	{
	public:

		BrickModelBase();
		virtual ~BrickModelBase();

	protected:
		virtual void assemble(/*Chunk &chunk, GLuint x, GLuint y, GLuint z*/) = 0;

		//Bricks hold the modelID not the model.
		//Rendering engine asks the brick what modelID it is, and then gets the correct model based off that.
	};
}

#endif