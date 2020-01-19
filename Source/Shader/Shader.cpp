#include "Shader.h"

Shader::Shader(GLchar *vertexPath_, GLchar *fragmentPath_) {
    GLuint vertex, fragment;
    std::string vertexCode;
    std::string fragmentCode;
    
    vertexPath = vertexPath_;
    fragmentPath = fragmentPath_;
    
    readShaderFile(vertexCode, fragmentCode);
    
    createVertexShader(vertexCode, vertex);
    createFragShader(fragmentCode, fragment);
    createShaderProgram(vertex, fragment);
    
    deleteShaderProgram(vertex, fragment);
}

Shader::~Shader() {
    glDeleteProgram(this->Program);
}

void Shader::readShaderFile(std::string &vertexCode, std::string &fragmentCode) {
    std::ifstream vertexShaderFile;
    std::ifstream fragShaderFile;
    std::stringstream vertexShaderStream;
    std::stringstream fragShaderStream;
    
    vertexShaderFile.exceptions(std::ifstream::badbit);
    fragShaderFile.exceptions(std::ifstream::badbit);
    
    try {
        vertexShaderFile.open(vertexPath);
        vertexShaderStream << vertexShaderFile.rdbuf();
        vertexShaderFile.close();
        vertexCode = vertexShaderStream.str();
    }
    catch (std::ifstream::failure err) {
        std::cout << "File Path : " << vertexPath << std::endl
            << "Error Reading Vertex Shader File" << std::endl; }
    
    try {
        fragShaderFile.open(fragmentPath);
        fragShaderStream << fragShaderFile.rdbuf();
        fragShaderFile.close();
        fragmentCode = fragShaderStream.str();
    }
    catch (std::ifstream::failure err) {
        std::cout << "File Path : " << fragmentPath << std::endl
            << "Error Reading Fragment Shader File" << std::endl; }
}

void Shader::createVertexShader(std::string &vertexCode, GLuint &vertex) {
    const GLchar *vertexShaderCode = vertexCode.c_str();
    
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexShaderCode, NULL);
    glCompileShader(vertex);
    
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "Error Compiling Vrtex Shader" << std::endl
            << "File Path : " << vertexPath << std::endl
            << infoLog << std::endl;
    }
}

void Shader::createFragShader(std::string &fragmentCode, GLuint &fragment) {
    const GLchar *fragShaderCode = fragmentCode.c_str();
    
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragShaderCode, NULL);
    glCompileShader(fragment);
    
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "Error Compiling Fragment Shader" << std::endl
            << "File Path : " << fragmentPath << std::endl
            << infoLog << std::endl;
    }
}

void Shader::createShaderProgram(GLuint &vertex, GLuint &fragment) {
    this->Program = glCreateProgram();
    glAttachShader(this->Program, vertex);
    glAttachShader(this->Program, fragment);
    glLinkProgram(this->Program);
    
    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(this->Program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->Program, 512, NULL, infoLog);
        std::cout << "Error Linking Shader Program" << std::endl
            << "File Path : " << vertexPath << " & " << fragmentPath << std::endl
            << infoLog << std::endl;
    }
}

void Shader::deleteShaderProgram(GLuint &vertex, GLuint &fragment) {
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use() {
    glUseProgram(this->Program);
}

void Shader::uniformMat4(const std::string &name, const glm::mat4 &value) {
    glUniformMatrix4fv(glGetUniformLocation(this->Program, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::uniformVec3(const std::string &name, const glm::vec3 &value) {
    glUniform3f(glGetUniformLocation(this->Program, name.c_str()), value.x, value.y, value.z);
}

void Shader::uniformVec3(const std::string &name, GLfloat x, GLfloat y, GLfloat z) {
    glUniform3f(glGetUniformLocation(this->Program, name.c_str()), x, y, z);
}

void Shader::uniformVec3(const std::string &name, GLfloat value) {
    glUniform3f(glGetUniformLocation(this->Program, name.c_str()), value, value, value);
}

