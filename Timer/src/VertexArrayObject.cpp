#include "VertexArrayObject.hpp"
#include<glad/glad.h>

VertexArrayObject::VertexArrayObject()
{
    m_VaoId  = 0;
    m_VboId  = 0;
    m_ViboId = 0;
}

VertexArrayObject::~VertexArrayObject()
{
    if(m_VboId)
        glDeleteBuffers(1,&m_VboId);

    if(m_ViboId)
        glDeleteBuffers(1,&m_ViboId);
    
    if(m_VaoId)
        glDeleteVertexArrays(1,&m_VaoId);
}

void VertexArrayObject::build(const Vertex3TexList &vertices, const IndexList &indices)
{
    glGenVertexArrays(1, &m_VaoId); 

    glGenBuffers(1,&m_VboId);

    glGenBuffers(1,&m_ViboId);

    glBindVertexArray(m_VaoId);
    
    glBindBuffer(GL_ARRAY_BUFFER,m_VboId);
    //dairenin vertex bilgileri vertex buffer a koplayanıyor
    glBufferData(GL_ARRAY_BUFFER,sizeof(Vertex3Tex)*vertices.size(),&vertices[0],GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    // kaplama bilgileri belirtiliyor
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_ViboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int)*indices.size(),&indices[0],GL_STATIC_DRAW);

    m_AttribList.push_back(0);
    m_AttribList.push_back(1);
    m_VertexCount = vertices.size();
    m_IndexCount = indices.size();
}

void VertexArrayObject::activate()
{
    glBindVertexArray(m_VaoId);
    for(auto next : m_AttribList)
    {
        glEnableVertexAttribArray(next);
    }
}

void VertexArrayObject::deactivate()
{
    for(auto next : m_AttribList)
    {
        glDisableVertexAttribArray(next);
    }
    glBindVertexArray(0);
}

int VertexArrayObject::getVertexCount()
{
    return m_VertexCount;
}

int VertexArrayObject::getIndexCount()
{
    return m_IndexCount;
}
