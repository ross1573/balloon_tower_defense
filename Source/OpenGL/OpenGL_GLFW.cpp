#include "OpenGL_GLFW.h"

OpenGL_GLFW::OpenGL_GLFW(const OpenGL_Settings &window_settings_, const GLfloat version_) {
    if (glfwInit() == NULL) {
        std::cout << "ERROR::INITIALIZE::GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, static_cast<int>(version_));
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, static_cast<int>(version_*10)%10);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, window_settings_.resizeable);
    glfwWindowHint(GLFW_SAMPLES, window_settings_.MSAA);
    
    GLFWmonitor* monitor = NULL;
    if (window_settings_.full_screen) monitor = glfwGetPrimaryMonitor();
    _window = glfwCreateWindow(window_settings_.width,
                               window_settings_.height,
                               window_settings_.title,
                               monitor, NULL);
    if (_window == NULL) {
        std::cout << "ERROR::CREATE::WINDOW" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(_window);
    
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "ERROR::INITAILIZE::GLEW" << std::endl;
        glfwDestroyWindow(_window);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    int frame_width, frame_height;
    glfwGetFramebufferSize(_window, &frame_width, &frame_height);
    glViewport(0, 0, frame_width, frame_height);
    
    glfwSwapInterval(window_settings_.vsync);
    glClearColor(0.1, 0.1, 0.1, 1.0);
}

OpenGL_GLFW::~OpenGL_GLFW() {
    glfwDestroyWindow(_window);
    glfwTerminate();
}

void OpenGL_GLFW::run() {
    gl_settings();
    setup();
    
    while (!glfwWindowShouldClose(_window)) {
        if (glfwGetKey(_window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(_window, GL_TRUE);
        }
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        render();
        glfwSwapBuffers(_window);
    }
}

GLboolean OpenGL_GLFW::getCursorPos(GLdouble &xPos, GLdouble &yPos) {
    if (glfwGetMouseButton(_window, 0) == GLFW_PRESS) {
        if (!key_stat) {
            glfwGetCursorPos(_window, &xPos, &yPos);
            key_stat = true;
            return true;
        }
        return false;
    }
    key_stat = false;
    return false;
}
