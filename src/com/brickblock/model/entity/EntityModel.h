#ifndef BB_ENTITYMODEL_H_
#define BB_ENTITYMODEL_H_

#include "../../util/load/resource/shader/ShaderProgram.h"
#include <glm/mat4x4.hpp>

namespace bb
{
	class Mesh;
	class Transform;
	struct TextureWrapper;
	class EntityModel
	{
		friend struct TextureFactory;

	public:
		EntityModel();
		virtual ~EntityModel();

		void lerpPosition(const GLdouble &alpha);

		virtual void update(const GLdouble &deltaTime);
		virtual void render(const GLdouble &alpha) = 0;

		const TextureWrapper* getTextureWrapper() const;

	protected:
		struct ComponentNode
		{
		public:
			//The mesh can be null
			const Mesh *mMESH;

			//Relative to the model
			Transform *mMeshTransform;

			//The parent component of the model
			ComponentNode *mParentComponent;

			ComponentNode(const Mesh *MESH, ComponentNode *parent = nullptr);
			~ComponentNode();

			void render(const GLdouble &alpha, const glm::mat4x4& modelTransform, const ShaderProgram &activeShader);
		};

		Transform *mModelTransform;
		TextureWrapper *mTextureWrapper;
	};
}

#endif