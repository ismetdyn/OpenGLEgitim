#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <GLFW/glfw3.h>
#include <vector>
#include <cmath>

#include "shaderprogram.hpp"
#include "square.hpp"
#include "texturemanager.hpp"
#include "VertexArrayObject.hpp"
#include "MeshManager.hpp"
#include "Mesh.hpp"
#include "Scene.hpp"
#include "WindowTransform.hpp"
#include "OpenGLManager.hpp"
#include "Timer.hpp"
#include "Transform.hpp"
#include "SceneNode.hpp"
#include "Arrow.hpp"

Transform* transform;
Scene* scene;
Mesh* mesh;
OpenGLManager* glManager;
ShaderProgram* program;
Timer* timer;
float angle;
float scale;
Arrow* arrow;
glm::mat4 mtxCam;
glm::mat4 mtxProj;
glm::mat4 mtxTransform;
glm::vec3 transition;


unsigned int texture;

void renderFunction()
{
    scene->getTextureManager()->activateTexture(GL_TEXTURE_2D, texture);
    scene->update();
    scene->draw();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
   if (key == GLFW_KEY_ESCAPE)
        glfwTerminate();   
    if(action==GLFW_PRESS)
    {
        if(key==GLFW_KEY_LEFT)  
        {
           transition.x -= 0.01;
        }
        if(key==GLFW_KEY_RIGHT) 
        {
            transition.x += 0.01;
        }    
        if(key==GLFW_KEY_UP)  
        {
            transition.y += 0.01;
        }
        if(key==GLFW_KEY_DOWN) 
        {
            transition.y -= 0.01;
        }                
    
        if(key==GLFW_KEY_Q)
        {
            scale -= 0.1;
        }    
        if(key==GLFW_KEY_W)
        {
            scale += 0.1;
        }    
           
    }  
           
}

int main(int argc,char** argv)
{
    glManager = new OpenGLManager();
    glManager->build(800,800);
    glManager->addRenderFunction(renderFunction);
    glManager->addKeyboardFunction(key_callback);
    glManager->setFPS(30);
    scene = new Scene();
    timer = new Timer();
    
    texture = scene->getTextureManager()->loadTexture("./images/container.jpg");

    arrow = new Arrow();
    scene->addNode(arrow);
    scene->build(glManager->getWindowPtr());
    
    timer->start();
    glManager->beginRenderLoop();
}