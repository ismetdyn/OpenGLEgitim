#include "Transform.hpp"
#include <glm/gtc/matrix_transform.hpp>

Transform::Transform()
{
    m_Position      = glm::vec3(0.0f,0.0f,0.0f);
    m_Scale         = glm::vec3(1.0f,1.0f,1.0f);
    m_EulerAngles   = glm::vec3(0.0f,0.0f,0.0f);
    m_MtxTransform  = glm::mat4(1);
    m_MtxParent     = glm::mat4(1);
}

glm::mat4 Transform::getMatrix()
{
    return m_MtxParent*m_MtxTransform; // Parent Combine Matrix*kendi matrixim;
                                       // kendi kombine matrixini yolla;
}

glm::vec3 Transform::getEulerAngles()
{
    return m_EulerAngles;
}

glm::vec3 Transform::getPosition()
{
    return m_Position;
}

glm::vec3 Transform::getScale()
{
    return m_Scale;
}

void Transform::setEulerAngles(const glm::vec3 &angles)
{
    m_EulerAngles = angles;
}

void Transform::setPosition(const glm::vec3 &position)
{
    m_Position = position;
}

void Transform::setScale(const glm::vec3 &scale)
{
    m_Scale = scale;
}

void Transform::setParentMatrix(const glm::mat4 &mtxParent)
{
    m_MtxParent = mtxParent;
}

void Transform::update()
{
    glm::mat4 mtxTranslate = glm::translate(glm::mat4(1),m_Position);
    glm::mat4 mtxScale     = glm::scale(glm::mat4(1), m_Scale);
    
    //zyx

    glm::mat4 mtxRotX = glm::rotate(glm::mat4(1), 
                                    glm::radians(m_EulerAngles.x),
                                    glm::vec3(1.0f,0.0f,0.0f));
    
    glm::mat4 mtxRotY = glm::rotate(glm::mat4(1), 
                                    glm::radians(m_EulerAngles.y),
                                    glm::vec3(0.0f,1.0f,0.0f));
    
    glm::mat4 mtxRotZ = glm::rotate(glm::mat4(1), 
                                    glm::radians(m_EulerAngles.z),
                                    glm::vec3(0.0f,0.0f,1.0f));

    glm::mat4 mtxRotation = mtxRotZ*mtxRotY*mtxRotX;

    //TRS
    m_MtxTransform = mtxTranslate*mtxRotation*mtxScale;
}
