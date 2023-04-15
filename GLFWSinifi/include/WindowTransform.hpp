#ifndef WINDOWTRANSFORM_HPP
#define WINDOWTRANSFORM_HPP

#include <glm/vec3.hpp>

class WindowTransform
{
public:
    void draw();
    void bindAngle(float* angle);
    void bindTransition(glm::vec3* transition);
private:
    float*      m_Angle;
    glm::vec3*  m_Transition;
};

#endif