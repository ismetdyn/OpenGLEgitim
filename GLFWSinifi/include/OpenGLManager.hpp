#ifndef OPENGLMANAGER_HPP
#define OPENGLMANAGER_HPP
#include <functional>
#include <vector>
class GLFWwindow;

typedef std::function<void()> RenderFunction;
typedef std::vector<RenderFunction> RenderFunctionList;

typedef std::function<void(GLFWwindow*,int,int,int,int)> KeyboardFunction;
typedef std::vector<KeyboardFunction> KeyboardFunctionList;

class OpenGLManager
{
public:
    OpenGLManager();
    bool build(int width, int height);

    void addRenderFunction(RenderFunction function);
    void addKeyboardFunction(KeyboardFunction function);

    void beginRenderLoop();
    GLFWwindow* getWindowPtr();
private:
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    RenderFunctionList      m_RenderFunctions;
    KeyboardFunctionList    m_KeyboardFunctions;
    GLFWwindow*             m_Window;
};

#endif