#include "MeshManager.hpp"
#include "VertexTypes.hpp"
#include "VertexArrayObject.hpp"
#include "Mesh.hpp"
#include "VertexArrayObjectManager.hpp"
#include <glm/trigonometric.hpp>

MeshManager::MeshManager(VertexArrayObjectManager* vaoManager)
{
    m_VaoManager = vaoManager;
}

Mesh *MeshManager::createCube()
{

    if(!m_VaoManager->getVao("cubeTex"))
    {
        Vertex3TexList  vertices;
        IndexList       indices;
        float length = 1.0f;
        glm::vec3 v[8];
        
        v[0] = glm::vec3(-length/2, -length/2, -length/2);
        v[1] = glm::vec3( length/2, -length/2, -length/2);
        v[2] = glm::vec3( length/2, -length/2,  length/2);
        v[3] = glm::vec3(-length/2, -length/2,  length/2);

        v[4] = glm::vec3(-length/2,  length/2, -length/2);
        v[5] = glm::vec3( length/2,  length/2, -length/2);
        v[6] = glm::vec3( length/2,  length/2,  length/2);
        v[7] = glm::vec3(-length/2,  length/2,  length/2);

        Vertex3Tex tempVertices[24];

        // on yuzey
        tempVertices[0].pos = v[7];
        tempVertices[1].pos = v[3];
        tempVertices[2].pos = v[2];
        tempVertices[3].pos = v[6];
        tempVertices[0].tex = glm::vec2(0.0f,1.0f);
        tempVertices[1].tex = glm::vec2(0.0f,0.0f);
        tempVertices[2].tex = glm::vec2(1.0f,0.0f);
        tempVertices[3].tex = glm::vec2(1.0f,1.0f);

        // sag yuzey
        tempVertices[4].pos = v[6];
        tempVertices[5].pos = v[2];
        tempVertices[6].pos = v[1];
        tempVertices[7].pos = v[5];
        tempVertices[4].tex = glm::vec2(0.0f,1.0f);
        tempVertices[5].tex = glm::vec2(0.0f,0.0f);
        tempVertices[6].tex = glm::vec2(1.0f,0.0f);
        tempVertices[7].tex = glm::vec2(1.0f,1.0f);

        // ust yuzey
        tempVertices[8 ].pos = v[4];
        tempVertices[9 ].pos = v[7];
        tempVertices[10].pos = v[6];
        tempVertices[11].pos = v[5];
        tempVertices[8 ].tex = glm::vec2(0.0f,1.0f);
        tempVertices[9 ].tex = glm::vec2(0.0f,0.0f);
        tempVertices[10].tex = glm::vec2(1.0f,0.0f);
        tempVertices[11].tex = glm::vec2(1.0f,1.0f);

        //alt yuzey
        tempVertices[12].pos = v[0];
        tempVertices[13].pos = v[3];
        tempVertices[14].pos = v[2];
        tempVertices[15].pos = v[1];
        tempVertices[12].tex = glm::vec2(0.0f,1.0f);
        tempVertices[13].tex = glm::vec2(0.0f,0.0f);
        tempVertices[14].tex = glm::vec2(1.0f,0.0f);
        tempVertices[15].tex = glm::vec2(1.0f,1.0f);

        // arka yuzey
        tempVertices[16].pos = v[4];
        tempVertices[17].pos = v[0];
        tempVertices[18].pos = v[1];
        tempVertices[19].pos = v[5];
        tempVertices[16].tex = glm::vec2(0.0f,1.0f);
        tempVertices[17].tex = glm::vec2(0.0f,0.0f);
        tempVertices[18].tex = glm::vec2(1.0f,0.0f);
        tempVertices[19].tex = glm::vec2(1.0f,1.0f);

        // sol yuzey
        tempVertices[20].pos = v[7];
        tempVertices[21].pos = v[3];
        tempVertices[22].pos = v[0];
        tempVertices[23].pos = v[4];
        tempVertices[20].tex = glm::vec2(0.0f,1.0f);
        tempVertices[21].tex = glm::vec2(0.0f,0.0f);
        tempVertices[22].tex = glm::vec2(1.0f,0.0f);
        tempVertices[23].tex = glm::vec2(1.0f,1.0f);

        for(int i= 0; i < 24; ++i)
        {
            vertices.push_back(tempVertices[i]);
        }

        for(int i = 0; i < 6; ++i)
        {
            int startIndex  = 4*i;
            indices.push_back(startIndex);
            indices.push_back(startIndex+1);
            indices.push_back(startIndex+2);

            indices.push_back(startIndex);
            indices.push_back(startIndex+2);
            indices.push_back(startIndex+3);
        }

        VertexArrayObject* vao = new VertexArrayObject();
        vao->build(vertices,indices);
        m_VaoManager->addNewObject("cubeTex",vao);
    }

    Mesh* mesh = new Mesh();
    mesh->m_Vao = m_VaoManager->getVao("cubeTex");
    mesh->m_IndexCount = m_VaoManager->getVao("cubeTex")->getIndexCount();
    mesh->m_VertexCount = m_VaoManager->getVao("cubeTex")->getIndexCount();

    return mesh;
}

Mesh* MeshManager::createCylinder( float length, 
                          float radius, 
                          ModelDetail detail,
                          const glm::vec4& frontColor,
                          const glm::vec4& middleColor)
{
    if(!m_VaoManager->getVao("cylinderColored"))
    {
        Vertex3ColorList vertices;
        IndexList        indices;
        float halfRadius = radius/2.0f;
        int angleIncrease;

        switch (detail){
            case ModelDetail::Low:
                angleIncrease = 30;
                break;
            case ModelDetail::Medium:
                angleIncrease = 20;
                break;
            case ModelDetail::High:
                angleIncrease = 10;
                break;
            case ModelDetail::Ultra:
                angleIncrease = 5;
                break;
            default:
                angleIncrease = 20;
                break;
        }

        int circleVertexCount = 360/angleIncrease;
        vertices.resize(circleVertexCount*4);
        int circleVertexCount2x = circleVertexCount*2;
        int circleVertexCount3x = circleVertexCount*3;
        float halfLength = length/2.0f;

        for(int i=0; i < circleVertexCount; i++)
        {
            Vertex3Color vertex;
            float angle = (float)i*angleIncrease;
            vertex.pos.x = glm::cos(glm::radians(angle))*halfRadius;
            vertex.pos.y = glm::sin(glm::radians(angle))*halfRadius;
            vertex.pos.z = halfLength;
            vertex.color = frontColor;
            
            // on yuz
            vertices[i] = vertex;

            vertices[i+circleVertexCount2x]         = vertex;
            vertices[i+circleVertexCount2x].color   = middleColor;

            // arka yuz
            vertex.pos.z = -halfLength;
            vertices[i+circleVertexCount]            = vertex;

            vertices[i+circleVertexCount3x]          = vertex;
            vertices[i+circleVertexCount3x].color    = middleColor;
        }


        // iki dairenin indekslerinin bulunmasi
        for(int i=0; i<circleVertexCount-2; i++)
        {
            indices.push_back(0);
            indices.push_back(i+1);
            indices.push_back(i+2);

            indices.push_back(circleVertexCount);
            indices.push_back(circleVertexCount+i+1);
            indices.push_back(circleVertexCount+i+2);
        }

        
        // arayuzun indeklerini bulma
        int startIndex = circleVertexCount2x;
        int currentIndex = startIndex;
        for(int i=0; i<circleVertexCount-1; i++)
        {
            indices.push_back(currentIndex);
            indices.push_back(currentIndex+circleVertexCount);
            indices.push_back(currentIndex+circleVertexCount+1);
            
            indices.push_back(currentIndex);
            indices.push_back(currentIndex+circleVertexCount+1);
            indices.push_back(currentIndex+1);

            currentIndex++;
        }

        indices.push_back(currentIndex);
        indices.push_back(currentIndex+circleVertexCount);
        indices.push_back(currentIndex+1);

        indices.push_back(currentIndex);
        indices.push_back(currentIndex+1);
        indices.push_back(startIndex);  

        VertexArrayObject* vao = new VertexArrayObject();
        vao->build(vertices,indices);
        m_VaoManager->addNewObject("cylinderColored",vao);
    }

    Mesh* mesh = new Mesh();
    mesh->m_Vao = m_VaoManager->getVao("cylinderColored");
    mesh->m_IndexCount = m_VaoManager->getVao("cylinderColored")->getIndexCount();
    mesh->m_VertexCount = m_VaoManager->getVao("cylinderColored")->getIndexCount();

    return mesh;
}
