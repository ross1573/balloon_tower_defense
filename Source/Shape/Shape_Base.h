#pragma once
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <cassert>


struct Transform_Data {
    glm::vec3 scale     = glm::vec3(1.0f);
    glm::vec3 translate = glm::vec3(0.0f);
    GLfloat rotate = 0.0f;
};


template <int VN = 3, int TN = 1>
class Shape {
private:
    GLuint _type = 0;
    
    std::vector<glm::vec3> _vertices = std::vector<glm::vec3>(VN);
    std::vector<glm::vec3> _color    = std::vector<glm::vec3>(VN);
    std::vector<GLuint>    _indices  = std::vector<GLuint>(TN*3);
    glm::mat4 _transform = glm::mat4(1.0f);
    
public:
    Shape(const glm::vec3 &center_ = glm::vec3(0.0f),
          const glm::vec3 &color_  = glm::vec3(1.0f),
          const Transform_Data &transform_ = Transform_Data());
    Shape(const glm::vec3 vertices_[VN],
          const glm::vec3 &color_ = glm::vec3(1.0f),
          const Transform_Data &transform_ = Transform_Data());
    
private:
    void init_vertex    (const glm::vec3 &center_);
    void init_vertex    (const glm::vec3 *vertices_);
    void init_indices   ();
    
    void init_color     (const glm::vec3 &color_);
    void init_transform (const Transform_Data &transform_);
    
    template <typename T> friend class Object_Base;
};
