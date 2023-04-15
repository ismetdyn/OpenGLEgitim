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
    void activate();
    void deactivate();
private:
    unsigned int m_VaoId;
    unsigned int m_VboId;
    unsigned int m_ViboId;
    std::vector<unsigned int> m_AttribList;
};

#endif