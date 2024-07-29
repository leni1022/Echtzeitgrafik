#include "shader.hpp"
#include <iostream>

Shader::Shader() {
    static const GLchar* simpleVertexShaderSource =
        "#version 330 core\n"
        "layout (location = 0) in vec3 position;\n"
        "layout (location = 1) in vec3 color;\n"
        "out vec3 ourColor;\n"
        "void main() {\n"
        " gl_Position = vec4(position, 1.0f);\n"
        " ourColor = color;\n"
        "}\0";

    static const GLchar* simpleFragmentShaderSource =
        "#version 330 core\n"
        "in vec3 ourColor;\n"
        "out vec4 color;\n"
        "void main() {\n"
        " color = vec4(ourColor, 1.0f);\n"
        "}\0";

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &simpleVertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &simpleFragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    programId = glCreateProgram();
    glAttachShader(programId, vertexShader);
    glAttachShader(programId, fragmentShader);
    glLinkProgram(programId);

    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(programId, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader() {
    glDeleteProgram(programId);
}

void Shader::use() {
    glUseProgram(programId);
}
