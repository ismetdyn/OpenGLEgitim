#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <vector>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include "shaderprogram.hpp"
#include "square.hpp"
#include "texturemanager.hpp"
#include "VertexArrayObject.hpp"
#include "MeshManager.hpp"
#include "Mesh.hpp"
#include "Scene.hpp"
#include "WindowTransform.hpp"
#include "OpenGLManager.hpp"

Scene* scene;
Mesh* mesh;
OpenGLManager* glManager;
ShaderProgram* program;
float angle;
float scale;

glm::mat4 mtxCam;
glm::mat4 mtxProj;
glm::mat4 mtxTransform;
glm::vec3 transition;


unsigned int texture;

void renderFunction()
{
        glm::mat4 mtxRotation   =  glm::rotate(glm::mat4(1),glm::radians(angle),glm::vec3(0.0f,1.0f,0.0f));
        glm::mat4 mtxTransition =  glm::translate(glm::mat4(1), transition);
        glm::mat4 mtxScale      =  glm::scale(glm::mat4(1), glm::vec3(scale));

        mtxTransform = mtxProj*mtxCam*mtxTransition*mtxRotation*mtxScale;
        
        angle += 2.0f;
        //çizimde kullanılacak olan program nesnesi aktif ediliyor
        program->use();

        scene->getTextureManager()->activateTexture(GL_TEXTURE_2D, texture);
        
        program->setVec4("uColor",glm::vec4(1.0f,0.0f,0.0f,1.0f));
        program->setMat4("uMtxTransform",&mtxTransform);

        mesh->draw();

        std::this_thread::sleep_for (std::chrono::milliseconds(70));

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
    scene = new Scene();

    texture = scene->getTextureManager()->loadTexture("./images/container.jpg");

    glm::mat4 mtxTransform(1);

    angle = 0.0f;
    scale = 1.0f;

    MeshManager* meshManager = scene->getMeshManager(); 
    mesh = meshManager->createCube();

    program = new ShaderProgram();

    program->attachShader("./shaders/simplevs.glsl",GL_VERTEX_SHADER);
    program->attachShader("./shaders/simplefs.glsl",GL_FRAGMENT_SHADER);
    program->link();

    program->addUniform("uColor");
    program->addUniform("uMtxTransform");
   
    //glm::vec3 camPosition(0.0f,0.0f,2.0f); 
    glm::vec3 camPosition(5.0f,1.0f,2.0f); 
    glm::vec3 camLookAt(0.0f,0.0f,0.0f);
    glm::vec3 camUp(0.0f,1.0f,0.0f);

    mtxCam = glm::lookAt(camPosition,camLookAt,camUp);
    mtxProj = glm::perspective<float>(glm::radians(90.0f), (800.0f/800.0f), 1.0f, 100.0f);

    scene->build(glManager->getWindowPtr());

    scene->getWindowTransform()->bindAngle(&angle);
    scene->getWindowTransform()->bindTransition(&transition);
    
    glManager->beginRenderLoop();
}