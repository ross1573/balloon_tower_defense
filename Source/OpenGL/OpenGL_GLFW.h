#pragma once
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>


struct OpenGL_Settings {
    GLint width;
    GLint height;
    const GLchar* title;
    
    GLboolean full_screen;
    GLboolean resizeable;
    GLboolean vsync;
    GLint MSAA;
};


class OpenGL_GLFW {
private:
    GLFWwindow* _window;
    GLboolean key_stat = false;
    
public:
    OpenGL_GLFW(const OpenGL_Settings &window_settings_, const GLfloat version_);
    ~OpenGL_GLFW();
    
    void run();
    GLboolean getCursorPos(GLdouble &xPos, GLdouble &yPos);
    
protected:
    void virtual gl_settings() = 0;
    void virtual setup() = 0;
    void virtual render() = 0;
};
