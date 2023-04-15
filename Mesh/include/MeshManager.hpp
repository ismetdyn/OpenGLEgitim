#ifndef MESHMANAGER_HPP
#define MESHMANAGER_HPP
#include <map>
#include <string>

class Mesh;
class VertexArrayObject;

class MeshManager
{
public:
    static MeshManager* getInstance();
    
    Mesh* createCube();
private:
    MeshManager();
    static MeshManager* m_Instance;
    std::map<std::string, VertexArrayObject*> m_VaoMap;
};

#endif