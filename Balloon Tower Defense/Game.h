#pragma once

#include "OpenGL_GLFW.h"
#include "Frame.h"
#include "Shader.h"
#include "Shape.h"

#include <vector>


class Game : public OpenGL_GLFW {
private:
    Frame frame_limiter;
    Shader shader;
    
public:
    Game(GLint width_, GLint height_, std::string title_, GLboolean full_screen_)
    : OpenGL_GLFW({ width_, height_, title_.c_str(), full_screen_, GL_FALSE, GL_FALSE, 4 }, 4.1f)
    , frame_limiter(120, false)
    , shader("Source/Shader/vs.vertex", "Source/Shader/fs.fragment") { }
    
protected:
    void gl_settings() override {
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
        glEnable(GL_BLEND);
    }
        
    void setup() override {
        
    }
    
    void render() override {
        shader.use();
        
        
        
        frame_limiter.limitFPS();
    }
};
