#ifndef MESHMANAGER_HPP
#define MESHMANAGER_HPP
#include <glm/vec4.hpp>

class Mesh;
class VertexArrayObjectManager;

enum class ModelDetail {Low, Medium, High, Ultra};

class MeshManager
{
public:
    MeshManager(VertexArrayObjectManager* vaoManager);
    Mesh* createCube();
    Mesh* createCylinder( float length=1.0f, 
                          float radius=1.0f, 
                          ModelDetail detail=ModelDetail::High,
                          const glm::vec4& frontColor=glm::vec4(1.0f,0.0f,0.0f,1.0f),
                          const glm::vec4& middleColor=glm::vec4(0.0f,1.0f,0.0f,1.0f));

    Mesh* createCone( float length=1.0f, 
                      float radius=1.0f, 
                      ModelDetail detail=ModelDetail::High,
                      const glm::vec4& frontColor=glm::vec4(1.0f,0.0f,0.0f,1.0f),
                      const glm::vec4& middleColor=glm::vec4(0.0f,1.0f,0.0f,1.0f));
private:
    VertexArrayObjectManager* m_VaoManager;
};

#endif