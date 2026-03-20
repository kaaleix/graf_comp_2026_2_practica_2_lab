#include "ShaderProgram.h"
#include <GL/glew.h>
#include <fstream>
#include <iostream>

ShaderProgram::ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath)
{
    std::string vertSrc  = readFile(vertexPath);
    std::string fragSrc  = readFile(fragmentPath);

    // compilar cada shader por separado
    unsigned int vert = compileShader(vertSrc, GL_VERTEX_SHADER);
    unsigned int frag = compileShader(fragSrc, GL_FRAGMENT_SHADER);

    // enlazar ambos en un programa
    ID = glCreateProgram();
    glAttachShader(ID, vert);
    glAttachShader(ID, frag);
    glLinkProgram(ID);

    // verificar que el enlace fue exitoso
    int success;
    char infoLog[512];
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cerr << "ERROR::PROGRAM::LINKING\n" << infoLog << std::endl;
    }

    // borramos los shaders individuales
    glDeleteShader(vert);
    glDeleteShader(frag);
}

void ShaderProgram::use() const {
    glUseProgram(ID);
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(ID);
}


std::string ShaderProgram::readFile(const std::string& filePath) const {
    std::ifstream fileStream(filePath, std::ios::in);
    if (!fileStream.is_open()) {
        std::cerr << "ERROR No se pudo abrir el shader" << filePath << std::endl;
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
    return content;
}

unsigned int ShaderProgram::compileShader(const std::string& source, unsigned int type) const {
    unsigned int shader = glCreateShader(type);
    const char* src = source.c_str(); // convierte string a const char* para OpenGL
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION\n" << infoLog << std::endl;
    }
    return shader;
}