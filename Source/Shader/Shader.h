/*
 * [[ Shader Program Creator ]]
 *
 *
 * # Description
 * Read shader files and create shader program
 * Shader file and program is for openGL
 *
 * # Requirement
 * GLEW
 *
 * # How to use
 * 1. Generate a 'Shader' type variable
 * 2. Use 'Use' function to use program
 *
 * # Form of the constructor
 * Shader "name"("vertex shader path", "fragment shader path")
 *                GLchar(char)          GLchar(char)
 *
 * # Note
 * -
 */

#pragma once
#define GLEW_STATIC

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>


class Shader {
public:
    GLuint Program;
    
private:
    GLchar *vertexPath;
    GLchar *fragmentPath;
    
public:
    Shader(GLchar *vertexPath_, GLchar *fragmentPath_);
    ~Shader();
    
    void use();
    void uniformMat4(const std::string &name, const glm::mat4 &Value);
    void uniformVec3(const std::string &name, const glm::vec3 &value);
    void uniformVec3(const std::string &name, GLfloat x, GLfloat y, GLfloat z);
    void uniformVec3(const std::string &name, GLfloat value);
    
private:
    void readShaderFile(std::string &vertexCode, std::string &fragmentCode);
    void createVertexShader(std::string &vertexCode, GLuint &vertex);
    void createFragShader(std::string &fragmentCode, GLuint &fragment);
    void createShaderProgram(GLuint &vertex, GLuint &fragment);
    void deleteShaderProgram(GLuint &vertex, GLuint &fragment);
};
