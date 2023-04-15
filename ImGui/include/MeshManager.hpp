#ifndef MESHMANAGER_HPP
#define MESHMANAGER_HPP

class Mesh;
class VertexArrayObjectManager;

class MeshManager
{
public:
    MeshManager(VertexArrayObjectManager* vaoManager);
    Mesh* createCube();
private:
    VertexArrayObjectManager* m_VaoManager;
};

#endif