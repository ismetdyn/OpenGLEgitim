#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

class Transform
{
public:
    Transform();

    glm::mat4   getMatrix();
    glm::vec3   getEulerAngles();
    glm::vec3   getPosition();
    glm::vec3   getScale();

    void        setEulerAngles(const glm::vec3& angles);
    void        setPosition(const glm::vec3& position);
    void        setScale(const glm::vec3& scale);
    void        update();
protected:
    glm::vec3   m_Position;
    glm::vec3   m_Scale;
    glm::vec3   m_EulerAngles;
    glm::mat4   m_MtxTransform;
};

#endif