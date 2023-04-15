#include "Arrow.hpp"
#include "MeshManager.hpp"

void Arrow::build(MeshManager *meshManager)
{
    setName("Arrow");

    m_ShaftLength = 2.0f;
    m_ShaftRadius = 0.2f;
    m_TipLength   = m_ShaftLength*0.2f;
    m_TipRadius   = m_ShaftRadius + 0.1f;

    Mesh* shaftMesh = meshManager->createCylinder();
    Mesh* tipMesh   = meshManager->createCone();

    SceneNode* shaftNode = new SceneNode(this);
    SceneNode* tipNode   = new SceneNode(this);

    shaftNode->setName("Shaft");
    tipNode->setName("Tip");

    shaftNode->adMesh(shaftMesh);
    tipNode->adMesh(tipMesh);

    shaftNode->getTransform()->setScale(glm::vec3(m_ShaftRadius,m_ShaftRadius,m_ShaftLength));
    tipNode->getTransform()->setScale(glm::vec3(m_TipRadius,m_TipLength,m_TipRadius));

    float tipOffset = (m_ShaftLength+m_TipLength)*0.5f; 

    tipNode->getTransform()->setPosition(glm::vec3(0.0f,0.0f,tipOffset));
    tipNode->getTransform()->setEulerAngles(glm::vec3(90.0f,0.0f,0.0f));

    addChild(shaftNode);
    addChild(tipNode);

    update();
}

void Arrow::start()
{
}

void Arrow::update()
{
    SceneNode::update();
}

void Arrow::draw(ShaderProgram *program)
{
    SceneNode::draw(program);
}
