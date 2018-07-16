#include "StandardBrickModel.h"
using namespace bb;

StandardBrickModel::StandardBrickModel() :
	mWALL(MeshResourcePack::standardBrickSide()),
	mBOTTOM(MeshResourcePack::standardBrickBottom())
{

}

StandardBrickModel::~StandardBrickModel()
{

}