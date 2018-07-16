#include "ModelTest.h"
#include "../../util/math/physics/Transform.h"
#include "../../util/math/MathHelper.h"
#include "../../util/logger/BBLogger.h"
#include "../../util/load/resource/pack/MeshResourcePack.h"
#include "../../util/load/resource/pack/ShaderResourcePack.h"
#include "../../render/RenderManager.h"
#include "../../util/math/MatrixUtil.h"
using namespace bb;

ModelTest::ModelTest() :
	EntityModel(), mTest(new ComponentNode(&MeshResourcePack::standardBrickTest(), nullptr)),
	mOrbit(new ComponentNode(&MeshResourcePack::standardBrickTest(), mTest)),
	mLightSource(new ComponentNode(&MeshResourcePack::cubeMesh(), nullptr))
{
	mLightSource->mMeshTransform->setScale(0.2f, 0.2f, 0.2f);
	mLightSource->mMeshTransform->setPosition(1.5f * (cos(MathHelper::toRadians(0.0))), 1.2f, 1.5f * (sin(MathHelper::toRadians(0.0))));
	mOrbit->mMeshTransform->setPosition(0.0, 0.4, 0.0);

	//mOrbit->mMeshTransform->setRotation(0.0, 180.0, 0.0);

	mLightSource->mMeshTransform->syncPrevTransforms();
	mOrbit->mMeshTransform->syncPrevTransforms();
	mTest->mMeshTransform->syncPrevTransforms();
}

ModelTest::~ModelTest()
{
	delete mTest;
	delete mOrbit;
}

void ModelTest::update(const GLdouble &deltaTime)
{
	EntityModel::update(deltaTime);
	mTest->mMeshTransform->update();
	mOrbit->mMeshTransform->update();
	mLightSource->mMeshTransform->update();

	Transform *orbitTransform = mOrbit->mMeshTransform;
	
	static GLdouble time = 0.0f;
	time += 1.0f;

	mLightSource->mMeshTransform->setPosition(1.5f * (cos(MathHelper::toRadians(time))), 0.5f, 1.5f * (sin(MathHelper::toRadians(time))));
	
	//orbitTransform->mRotation.y += (30.0f * deltaTime * (cos(MathHelper::toRadians(time))));
	orbitTransform->mRotation.y += (30.0f * deltaTime);


	//mModelTransform->mPosition.y = (3.0f * (sin(MathHelper::toRadians(time))));
	//mTest->mMeshTransform->mRotation.z += (2.0f * deltaTime);

	//mModelTransform->mScale += (5.0f * deltaTime * (sin(MathHelper::toRadians(time))));
}

void ModelTest::render(const GLdouble &alpha)
{
	EntityModel::lerpPosition(alpha);

	glm::vec3 modelColor = glm::vec3(0.8, 0.5, 0.4);
	glm::vec3 lightColor = glm::vec3(1.0, 1.0, 1.0);

	const ShaderProgram &modelShader = ShaderResourcePack::testModelProgram();
	Camera &camera = RenderManager::getInstance().getCamera();

	modelShader.use();

	glm::mat4 viewMat = camera.getViewMatrix();
	modelShader.loadMat4("viewMatrix", GL_FALSE, viewMat);
	modelShader.loadMat4("projectionMatrix", GL_FALSE, camera.getProjectionMatrix());

	modelShader.loadVec3("modelColor", modelColor);
	modelShader.loadVec3("lightColor", lightColor);
	modelShader.loadVec3("lightPos", mLightSource->mMeshTransform->mLerpedPosition);

	modelShader.loadMat3("normalMatrix", GL_FALSE, MatrixUtil::createNormalMat(mTest->mMeshTransform->getTransformationMat(), viewMat));
	mTest->render(alpha, mModelTransform->getTransformationMat(), ShaderResourcePack::testModelProgram());

	modelShader.loadMat3("normalMatrix", GL_FALSE, MatrixUtil::createNormalMat(mOrbit->mMeshTransform->getTransformationMat(), viewMat));
	mOrbit->render(alpha, mModelTransform->getTransformationMat(), ShaderResourcePack::testModelProgram());

	const ShaderProgram &lightShader = ShaderResourcePack::testLightProgram();
	lightShader.use();

	lightShader.loadMat4("viewMatrix", GL_FALSE, camera.getViewMatrix());
	lightShader.loadMat4("projectionMatrix", GL_FALSE, camera.getProjectionMatrix());

	mLightSource->render(alpha, mModelTransform->getTransformationMat(), ShaderResourcePack::testLightProgram());
}