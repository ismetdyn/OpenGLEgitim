#ifndef WINDOWTRANSFORM_HPP
#define WINDOWTRANSFORM_HPP
#include <glm/vec3.hpp>

class Transform;

class WindowTransform
{
public:
    void        draw();
    void        setActiveTransform(Transform* transform);
private:

    Transform*  m_ActiveTransform;
};

#endif