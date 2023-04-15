#ifndef MESH_HPP
#define MESH_HPP

class VertexArrayObject;
class MeshManager;
class Mesh
{
public:
    void draw();
private:
    VertexArrayObject* m_Vao;
    unsigned int m_IndexCount;
    unsigned int m_VertexCount;
    friend MeshManager;
};

#endif