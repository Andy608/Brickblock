#ifndef BB_STANDARDBRICKMODEL_H_
#define BB_STANDARDBRICKMODEL_H_

#include "../BrickModelBase.h"
#include "../../../util/load/resource/pack/MeshResourcePack.h"

namespace bb
{
	class StandardBrickModel : public BrickModelBase
	{
	public:
		StandardBrickModel();
		virtual ~StandardBrickModel();

		virtual void assemble(/*Chunk &chunk, GLuint x, GLuint y, GLuint z, GLuint width, GLuint height, GLuint length*/) = 0;
	
	protected:
		const Mesh &mWALL;
		const Mesh &mBOTTOM;
	};
}

#endif