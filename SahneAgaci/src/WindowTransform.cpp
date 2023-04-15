#include <iostream>
#include "WindowTransform.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Transform.hpp"
#include "SceneNode.hpp"

void WindowTransform::draw()
{
    ImGui::Begin("Donusum Penceresi");
    ImGui::Text("%s",m_ActiveNode->getName().c_str());
    ImGui::Separator();
    
    glm::vec3 angles    = m_ActiveNode->getTransform()->getEulerAngles();
    glm::vec3 position  = m_ActiveNode->getTransform()->getPosition();

    ImGui::SliderFloat3("rotation",&angles.x,0,360);
    ImGui::SliderFloat3("transition",&position.x, -10,10);

    ImGui::End();
    
    
    m_ActiveNode->getTransform()->setPosition(position);
    m_ActiveNode->getTransform()->setEulerAngles(angles);
    
}

void WindowTransform::setActiveNode(SceneNode *node)
{
    m_ActiveNode = node;
}
