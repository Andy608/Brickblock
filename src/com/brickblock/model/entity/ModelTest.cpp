#include "ModelTest.h"
#include "../../util/math/physics/Transform.h"
#include "../../util/math/MathHelper.h"
#include "../../util/logger/BBLogger.h"
#include "../../util/load/resource/pack/MeshResourcePack.h"
using namespace bb;

ModelTest::ModelTest() :
	EntityModel(), mTest(new ComponentNode(&MeshResourcePack::standardBrickTest(), nullptr)),
		mOrbit(new ComponentNode(&MeshResourcePack::standardBrickTest(), mTest))
{

	//mModelTransform->addPosition(1.0, 0.0, 0.0);

	mTest->mMeshTransform->addPosition(0.0, 0.0, 0.0);

	Transform *orbitTransform = mOrbit->mMeshTransform;
	orbitTransform->setPosition(0.0, 0.5, 0.0);
	//orbitTransform->setScale(0.5, 0.5, 0.5);
}

ModelTest::~ModelTest()
{
	delete mTest;
	delete mOrbit;
}

void ModelTest::update(const GLdouble &deltaTime)
{
	Transform *orbitTransform = mOrbit->mMeshTransform;
	
	static GLdouble time = 0.0f;
	time += 1.0f;

	//orbitTransform->mPosition.x = (3.0f * (cos(MathHelper::toRadians(time))));
	//orbitTransform->mPosition.z = (3.0f * (sin(MathHelper::toRadians(time))));
	
	//orbitTransform->mRotation.y += (30.0f * deltaTime * (cos(MathHelper::toRadians(time))));
	orbitTransform->mRotation.y += (30.0f * deltaTime);


	//mModelTransform->mPosition.y = (3.0f * (sin(MathHelper::toRadians(time))));
	//mTest->mMeshTransform->mRotation.z += (2.0f * deltaTime);

	//mModelTransform->mScale += (5.0f * deltaTime * (sin(MathHelper::toRadians(time))));

	EntityModel::update(deltaTime);
	mTest->mMeshTransform->update();
	mOrbit->mMeshTransform->update();
}

void ModelTest::render(const GLdouble &alpha, const ShaderProgram &activeShader)
{
	EntityModel::lerpPosition(alpha);

	mTest->render(alpha, mModelTransform->getTransformationMat(), activeShader);
	mOrbit->render(alpha, mModelTransform->getTransformationMat(), activeShader);
}