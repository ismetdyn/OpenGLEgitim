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

Scene* scene;
Mesh* mesh;

float angle;
glm::vec3 position;
float scale;

unsigned int texture;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
   if (key == GLFW_KEY_ESCAPE)
        glfwTerminate();   
    if(action==GLFW_PRESS)
    {
        if(key==GLFW_KEY_LEFT)  
        {
           position.x -= 0.01;
        }
        if(key==GLFW_KEY_RIGHT) 
        {
            position.x += 0.01;
        }    
        if(key==GLFW_KEY_UP)  
        {
            position.y += 0.01;
        }
        if(key==GLFW_KEY_DOWN) 
        {
            position.y -= 0.01;
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
    if(!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(800,800,"İLk Programım",NULL,NULL);

    if(window==NULL)
    {
        std::cout<<"Pencere Olusturulamadi"<<std::endl;

        glfwTerminate();

        return -1;
    }    
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    } 

    scene = new Scene();

    texture = scene->getTextureManager()->loadTexture("./images/container.jpg");

    glm::mat4 mtxTransform(1);

    angle = 0.0f;
    position = glm::vec3(0.0f,0.0f, 0.0f);
    scale = 1.0f;

    MeshManager* meshManager = scene->getMeshManager(); 
    mesh = meshManager->createCube();

    ShaderProgram program;

    program.attachShader("./shaders/simplevs.glsl",GL_VERTEX_SHADER);
    program.attachShader("./shaders/simplefs.glsl",GL_FRAGMENT_SHADER);
    program.link();

    program.addUniform("uColor");
    program.addUniform("uMtxTransform");
   
    //glm::vec3 camPosition(0.0f,0.0f,2.0f); 
    glm::vec3 camPosition(5.0f,1.0f,2.0f); 
    glm::vec3 camLookAt(0.0f,0.0f,0.0f);
    glm::vec3 camUp(0.0f,1.0f,0.0f);

    glm::mat4 mtxCam = glm::lookAt(camPosition,camLookAt,camUp);
    glm::mat4 mtxProj = glm::perspective<float>(glm::radians(90.0f), (800.0f/800.0f), 1.0f, 100.0f);

    scene->build(window);

    glm::vec3 transition;

    scene->getWindowTransform()->bindAngle(&angle);
    scene->getWindowTransform()->bindTransition(&transition);

    glEnable(GL_DEPTH_TEST);
    while(!glfwWindowShouldClose(window))
    {
        //oluşturulacak resim başlangıç rengine boyanıyor
        glClearColor(0.0f, 0.4f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        glm::mat4 mtxRotation =  glm::rotate(glm::mat4(1),glm::radians(angle),glm::vec3(0.0f,1.0f,0.0f));
       
        glm::mat4 mtxTransition = glm::translate(glm::mat4(1), transition);
        
        mtxTransform = mtxProj*mtxCam*mtxTransition*mtxRotation;
        
        angle += 2.0f;
        //çizimde kullanılacak olan program nesnesi aktif ediliyor
        program.use();

        scene->getTextureManager()->activateTexture(GL_TEXTURE_2D, texture);
        
        program.setVec4("uColor",glm::vec4(1.0f,0.0f,0.0f,1.0f));
        program.setMat4("uMtxTransform",&mtxTransform);

        mesh->draw();

        std::this_thread::sleep_for (std::chrono::milliseconds(70));

        scene->draw();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}