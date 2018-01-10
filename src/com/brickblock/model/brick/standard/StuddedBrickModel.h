#ifndef BB_STUDDEDBRICKMODEL_H_
#define BB_STUDDEDBRICKMODEL_H_

#include "StandardBrickModel.h"

namespace bb
{
	class StuddedBrickModel : public StandardBrickModel
	{
	public:
		StuddedBrickModel();
		~StuddedBrickModel();

		virtual void assemble(/*Chunk &chunk, GLuint x, GLuint y, GLuint z, GLuint width, GLuint height, GLuint length*/);

	protected:
		const Mesh &mTOP;
	};
}

#endif