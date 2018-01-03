#include "ModelTest.h"
#include "../resource/pack/MeshResourcePack.h"
#include "../../util/math/physics/Transform.h"
#include "../../util/logger/BBLogger.h"
using namespace bb;

ModelTest::ModelTest() :
	Model()
{
	mRoot = new ComponentNode(0, &MeshResourcePack::getTestMesh());
	mModelTransform->addPosition(0.0, 0.0, 0.0);
}

void ModelTest::update(const GLdouble& DELTA_TIME)
{
	//Make custom sin table in future.
	//static GLdouble time = 0.0f;
	//time += DELTA_TIME;
	//mModelTransform->addPosition(static_cast<GLfloat>(std::sin(time)), 0.0, 0.0);
	//BBLogger::logDebug("ModelTest.cpp", "TRANSFORM: " 
	//	+ std::to_string(mModelTransform->getPosition().x) + " "
	//	+ std::to_string(mModelTransform->getPosition().y) + " "
	//  + std::to_string(mModelTransform->getPosition().z));
}