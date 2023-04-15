#include <iostream>
#include "WindowTransform.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Transform.hpp"

void WindowTransform::draw()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();
    ImGui::Begin("Donusum Penceresi");
    if(ImGui::Button("Tikla!"))
    {
        std::cout << "Tiklandi!" << std::endl;
    }
    
    glm::vec3 angles    = m_ActiveTransform->getEulerAngles();
    glm::vec3 position  = m_ActiveTransform->getPosition();

    ImGui::SliderFloat3("rotation",&angles.x,0,360);
    ImGui::SliderFloat3("transition",&position.x, -10,10);

    ImGui::End();
    ImGui::EndFrame();
    ImGui::Render();

    m_ActiveTransform->setPosition(position);
    m_ActiveTransform->setEulerAngles(angles);
    
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


void WindowTransform::setActiveTransform(Transform *transform)
{
    m_ActiveTransform = transform;
}
