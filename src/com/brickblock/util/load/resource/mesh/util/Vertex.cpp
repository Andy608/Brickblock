#include "Vertex.h"
using namespace bb;

Vertex::Vertex(GLuint pos, GLuint tex, GLuint norm) :
	mPositionIndex(pos), mTextureIndex(tex), mNormalIndex(norm)
{

}

GLboolean Vertex::operator==(const Vertex & another)
{
	return (mPositionIndex == another.mPositionIndex &&
			mTextureIndex == another.mTextureIndex &&
			mNormalIndex == another.mNormalIndex);
}
