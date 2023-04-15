#include "WindowScene.hpp"
#include "SceneNode.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <iostream>

WindowScene::WindowScene(SceneNode *root)
{
    m_Root = root;
    m_ActiveNode = root;
}

void WindowScene::draw()
{
    ImGui::Begin("Sahne Penceresi");
        drawSceneNode(m_Root);
    ImGui::End();
}

void WindowScene::drawSceneNode(SceneNode *node)
{
    if(node) 
    {
        unsigned int flags = ImGuiTreeNodeFlags_DefaultOpen;
        if(node == m_ActiveNode)
        {
            flags |= ImGuiTreeNodeFlags_Selected;
        }
        if(ImGui::TreeNodeEx(node->getName().c_str(), flags))
        {
            if(ImGui::IsItemActivated())
            {
                m_ActiveNode = node;
            }
            for(int i=0; i<node->getChildCount(); i++)
            {
                drawSceneNode(node->getChild(i));
            }

            ImGui::TreePop(); 
        }
    }
}

SceneNode *WindowScene::getActiveNode()
{
    return m_ActiveNode;
}
