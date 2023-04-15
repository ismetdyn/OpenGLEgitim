#ifndef SCENENODE_HPP
#define SCENENODE_HPP
#include <vector>
#include <string>
#include "Transform.hpp"
#include "Mesh.hpp"

class ShaderProgram;

class SceneNode
{
public:
    typedef std::vector<SceneNode*> SceneNodeList;
    SceneNode(SceneNode* parent = nullptr);

    virtual void build(MeshManager* meshManager=0);
    virtual void start();
    virtual void update();
    virtual void draw(ShaderProgram* program);

    void        addChild(SceneNode* child);
    void        adMesh(Mesh* mesh);
    void        setParent(SceneNode* child);
    void        setName(const std::string& name);
    void        setVisible(bool visible);
    void        setTransform(Transform* transform);

    std::string getName();
    SceneNode*  getChild(int index);
    SceneNode*  getParent();
    Transform*  getTransform();
    int         getChildCount();       
    bool        getVisible();

protected:
    bool                m_IsVisiable;
    std::string         m_Name;
    SceneNodeList       m_Childs;
    SceneNode*          m_Parent;
    Transform*          m_Transform;
    MeshList            m_Meshes;
};


#endif