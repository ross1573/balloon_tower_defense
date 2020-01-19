#pragma once
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <vector>
#include <list>
#include <map>

#include "Shape.h"


template <typename T>
class Object_Base {
private:
    std::vector<glm::vec3> _vertices;
    std::vector<glm::vec3> _colors;
    std::vector<GLuint> _indices;
    std::vector<glm::mat4> _transforms;
    
    GLuint _vao;
    GLuint _vbo;
    GLuint _ebo;
    
    GLuint _id;
    static GLuint _id_count;
    
public:
    Object_Base();
    
    void append(const T &shape_);
    void erase(const GLuint _id);
    void draw();
};


template <typename T>
class Object {
private:
    std::map<GLuint, Triangle>  _triangle;
    std::map<GLuint, Square>    _square;
    
public:
    Object();
    
    void add(const T &shape_);
    void remove(const GLuint _id);
    void draw();
};


class Object_Static {
private:
    std::list<Object_Base<Triangle>>    _triangle;
    std::list<Object_Base<Square>>      _square;
    
public:
    Object_Static();
};
