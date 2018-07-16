#ifndef BB_MESH_H_
#define BB_MESH_H_

#include "../Resource.h"
#include "../../../../util/filesystem/file/FileLocation.h"
#include "util/VBOWrapper.h"
#include <string>
#include <glm/vec4.hpp>

namespace bb
{
	class FileLocation;
	struct VAOWrapper;
	struct EBOWrapper;
	class Mesh : public Resource
	{
	public:
		friend struct MeshFactory;
		//Load mesh from file. (Make another constructor in the future to load not from file --subclass loading).
		Mesh(std::string resourceID, FileLocation *meshDataLocation);
		virtual ~Mesh();

		const Mesh& operator=(const Mesh& another);

		virtual void load();
		virtual void unload();

		VAOWrapper* const getVAOWrapper() const;
		VBOWrapper* const getVBOWrapper(const VBOWrapper::BufferType& BUFFER_TYPE) const;
		EBOWrapper* const getEBOWrapper() const;

		virtual void render(const GLdouble& deltaTime) const;

	private:
		static const std::string CLASS_NAME;

		VAOWrapper *mVAOWrapper;
		std::vector<VBOWrapper*>* mVBOWrappers;
		EBOWrapper *mEBOWrapper;

		//Null if not made from file.
		FileLocation *mMeshDataLocation;

		glm::vec4 mColor; //values between 0-1

		virtual void prepareMesh();
		
		void setElementBuffer(EBOWrapper *newWrapper);
		void addBufferData(VBOWrapper* newBufferData);

		void clearBufferData();
	};
}

#endif