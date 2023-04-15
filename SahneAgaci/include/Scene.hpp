#ifndef SCENE_HPP
#define SCENE_HPP

class MeshManager;
class TextureManager;
class VertexArrayObjectManager;
class WindowTransform;
class GLFWwindow;
class SceneNode;
class ShaderProgram;
class WindowScene;

class Scene
{
public:
    Scene();

    void build(GLFWwindow* window);
    void addNode(SceneNode* newNode);
    void update();
    void draw();
    void drawGui();

    MeshManager*                getMeshManager();
    TextureManager*             getTextureManager();
    VertexArrayObjectManager*   getVaoManager();
    WindowTransform*            getWindowTransform();
private:
    MeshManager*                m_MeshManager;
    TextureManager*             m_TextureManager;
    VertexArrayObjectManager*   m_VaoManager;
    WindowTransform*            m_WindowTransform;
    WindowScene*                m_WindowScene;
    SceneNode*                  m_Root;
    ShaderProgram*              m_ShaderProgram;
};

#endif