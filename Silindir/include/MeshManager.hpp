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
    Mesh* createCylinder( float length, 
                          float radius, 
                          ModelDetail detail,
                          const glm::vec4& frontColor,
                          const glm::vec4& middleColor);
private:
    VertexArrayObjectManager* m_VaoManager;
};

#endif