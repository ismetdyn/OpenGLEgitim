#ifndef ARROW_HPP
#define ARROW_HPP
#include "SceneNode.hpp"

class Arrow : public SceneNode
{
public:
    virtual void build(MeshManager* meshManager=0) override;
    virtual void start() override;
    virtual void update() override;
    virtual void draw(ShaderProgram* program) override;
private:
    float   m_ShaftLength;
    float   m_ShaftRadius;
    float   m_TipLength;
    float   m_TipRadius;
};

#endif