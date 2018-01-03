#ifndef BB_MODEL_H_
#define BB_MODEL_H_

#include "../resource/Resource.h"
#include <vector>

namespace bb
{
	class Mesh;
	class Transform;
	class Model
	{
	public:
		Model();
		virtual ~Model();

		virtual void update(const GLdouble& DELTA_TIME) = 0;
		void render(const GLdouble& DELTA_TIME);

	protected:
		struct ComponentNode
		{
		public:
			//The mesh can be null
			const Mesh *mMESH;

			//The child nodes that move relative to their parents
			std::vector<ComponentNode*> *mChildNodes;

			//Relative to the model
			Transform *mMeshTransform;

			ComponentNode(GLuint id, const Mesh *MESH);
			~ComponentNode();

			void addChild(ComponentNode *node);
			void clearComponents();
			void removeChild(GLuint componentID);

			const GLuint& getComponentID() const;

		private:
			//Used to track components in a model. All IDs are unique in a given model.
			GLuint mComponentID;
		};

		//Build nodes from the base up, then add them to the root.
		ComponentNode *mRoot;
		Transform *mModelTransform;

		void renderComponents(ComponentNode *node, const GLdouble& DELTA_TIME);
	};
}

#endif