#ifndef VERTEXARRAYOBJECT_HPP
#define VERTEXARRAYOBJECT_HPP
#include "VertexTypes.hpp"

class VertexArrayObject
{
public:
    VertexArrayObject();
    ~VertexArrayObject();
    
    void build(const Vertex3TexList& vertices,
                const IndexList& indices);
    void build(const Vertex3ColorList& vertices,
                const IndexList& indices);
    void activate();
    void deactivate();
    int getVertexCount();
    int getIndexCount();
private:
    unsigned int m_VaoId;
    unsigned int m_VboId;
    unsigned int m_ViboId;
    unsigned int m_IndexCount;
    unsigned int m_VertexCount;

    std::vector<unsigned int> m_AttribList;
};

#endif