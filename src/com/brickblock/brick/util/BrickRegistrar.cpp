#include "BrickRegistrar.h"
#include "../../util/logger/BBLogger.h"
#include "../Brick.h"
using namespace bb;

BrickRegistrar *BrickRegistrar::mpsInstance = nullptr;

void BrickRegistrar::registerBrick(const Brick *brick)
{
	std::vector<const Brick*> &registry = mpsInstance->mBrickRegistry;

	try
	{
		GLuint i;
		for (i = 0; i < registry.size(); ++i)
		{
			if (brick->getBrickID() == registry.at(i)->getBrickID())
			{
				std::string error = "The Brick ID: " + registry.at(i)->getUnlocalizedName() + " is already being used.";
				throw std::invalid_argument(error);
			}
		}

		BBLogger::logDebug("BrickRegistrar", "Registering: " + brick->getUnlocalizedName());
		registry.push_back(brick);
	}
	catch (std::invalid_argument e)
	{
		//brick id is already registered.
		BBLogger::logError("BrickRegistrar", e.what());
	}
}

void BrickRegistrar::initInstance()
{
	if (!mpsInstance)
	{
		mpsInstance = new BrickRegistrar();
	}
	else
	{
		BBLogger::logWarn("BrickRegistrar", "BrickRegistry is already initialized.");
	}
}

void BrickRegistrar::cleanupInstance()
{
	delete mpsInstance;
}

BrickRegistrar::~BrickRegistrar()
{
	GLuint i;
	const Brick *pBRICK;

	for (i = 0; i < mBrickRegistry.size(); ++i)
	{
		pBRICK = mBrickRegistry.at(i);
		BBLogger::logWarn("BrickRegistrar", "Deleting BrickID: " + pBRICK->getUnlocalizedName());
		delete pBRICK;
	}

	mBrickRegistry.clear();
}