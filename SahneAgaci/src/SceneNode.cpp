#include "SceneNode.hpp"
#include "shaderprogram.hpp"

SceneNode::SceneNode(SceneNode *parent)
{
    m_Parent = parent;
    m_IsVisiable = true;
    m_Transform = new Transform();
}

void SceneNode::build(MeshManager *meshManager)
{
    for(auto nextNode : m_Childs)
    {
        nextNode->build(meshManager);
    }
}

void SceneNode::start()
{

}

void SceneNode::update()
{
    // dugumu guncelle
    m_Transform->update();

    // cocuklar guncellensin
    for(auto nextNode : m_Childs)
    {
        nextNode->getTransform()->setParentMatrix(m_Transform->getMatrix());
        nextNode->update();
    }
}

void SceneNode::draw(ShaderProgram *program)
{
    glm::mat4 mtxTransform = m_Transform->getMatrix();
    program->setMat4("uMtxTransform",&mtxTransform);
    if(m_IsVisiable)
    {
        for(auto nextMesh : m_Meshes)
        {
            nextMesh->draw();
        }
    }

    for(auto nextNode : m_Childs)
    {
        nextNode->draw(program);
    }
}

void SceneNode::addChild(SceneNode *child)
{
    m_Childs.push_back(child);
    if(child->getParent())
        child->setParent(this);
}

void SceneNode::adMesh(Mesh *mesh)
{
    m_Meshes.push_back(mesh);
}

void SceneNode::setParent(SceneNode *child)
{
    m_Parent = child;
}

void SceneNode::setName(const std::string &name)
{
    m_Name = name;
}

void SceneNode::setVisible(bool visible)
{
    m_IsVisiable = visible;
}

void SceneNode::setTransform(Transform *transform)
{
    if(m_Transform)
        delete m_Transform;
    
    m_Transform = transform;
}

std::string SceneNode::getName()
{
    return m_Name;
}

SceneNode *SceneNode::getChild(int index)
{
    if(index<m_Childs.size())
        return m_Childs[index];

    return nullptr;
}

SceneNode *SceneNode::getParent()
{
    return m_Parent;
}

Transform *SceneNode::getTransform()
{
    return m_Transform;
}

int SceneNode::getChildCount()
{
    return m_Childs.size();
}

bool SceneNode::getVisible()
{
    return m_IsVisiable;
}
