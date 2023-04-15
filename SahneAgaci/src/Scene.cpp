#include "Scene.hpp"
#include "VertexArrayObjectManager.hpp"
#include "MeshManager.hpp"
#include "texturemanager.hpp"
#include "WindowTransform.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "SceneNode.hpp"
#include "WindowScene.hpp"
#include "shaderprogram.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "glad/glad.h"

Scene::Scene()
{
    m_VaoManager      = new VertexArrayObjectManager();
    m_MeshManager     = new MeshManager(m_VaoManager);
    m_TextureManager  = new TextureManager();
    m_WindowTransform = new WindowTransform();
    m_Root            = new SceneNode();
    m_Root->setName("Scene Root");
    m_WindowScene     = new WindowScene(m_Root);
}

void Scene::build(GLFWwindow *window)
{
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window,true);
    ImGui_ImplOpenGL3_Init();

    ImGui::StyleColorsDark();

    m_ShaderProgram = new ShaderProgram();

    m_ShaderProgram->attachShader("./shaders/colorvs.glsl",GL_VERTEX_SHADER);
    m_ShaderProgram->attachShader("./shaders/colorfs.glsl",GL_FRAGMENT_SHADER);
    m_ShaderProgram->link();

    m_ShaderProgram->addUniform("uMtxTransform");
    m_ShaderProgram->addUniform("uMtxCamera");
    m_ShaderProgram->addUniform("uMtxProjection");

    m_WindowTransform->setActiveNode(m_Root);
    m_Root->build(m_MeshManager);
}

void Scene::addNode(SceneNode *newNode)
{
    m_Root->addChild(newNode);
}

void Scene::update()
{
    m_Root->update();
}

void Scene::draw()
{
    m_ShaderProgram->use();

    glm::vec3 camPosition(2.0f,2.0f,0.0f); 
    glm::vec3 camLookAt(0.0f,0.0f,0.0f);
    glm::vec3 camUp(0.0f,1.0f,0.0f); 

    glm::mat4 mtxCam  = glm::lookAt(camPosition,camLookAt,camUp);
    glm::mat4 mtxProj = glm::perspective<float>(glm::radians(90.0f), (800.0f/800.0f), 1.0f, 100.0f);

    m_ShaderProgram->setMat4("uMtxCamera",&mtxCam);
    m_ShaderProgram->setMat4("uMtxProjection",&mtxProj);

    m_Root->draw(m_ShaderProgram);

    drawGui();
}

void Scene::drawGui()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    m_WindowTransform->draw();
    m_WindowScene->draw();
    SceneNode* activeNode = m_WindowScene->getActiveNode();
    m_WindowTransform->setActiveNode(activeNode);

    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

MeshManager *Scene::getMeshManager()
{
    return m_MeshManager;
}

TextureManager *Scene::getTextureManager()
{
    return m_TextureManager;
}

VertexArrayObjectManager *Scene::getVaoManager()
{
    return m_VaoManager;
}

WindowTransform *Scene::getWindowTransform()
{
    return m_WindowTransform;
}
