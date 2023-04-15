#ifndef WINDOWTRANSFORM_HPP
#define WINDOWTRANSFORM_HPP
#include <glm/vec3.hpp>

class Transform;
class SceneNode;

class WindowTransform
{
public:
    void        draw();
    void        setActiveNode(SceneNode* node);
private:

    SceneNode*  m_ActiveNode;
};

#endif