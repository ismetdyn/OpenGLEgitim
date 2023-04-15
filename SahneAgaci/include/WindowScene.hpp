#ifndef WINDOWSCENE_HPP
#define WINDOWSCENE_HPP


class SceneNode;

class WindowScene
{
public:
    WindowScene(SceneNode* root);
    void draw();
    void drawSceneNode(SceneNode* node);
    SceneNode* getActiveNode();
private:
    SceneNode*      m_Root;
    SceneNode*      m_ActiveNode;
};

#endif