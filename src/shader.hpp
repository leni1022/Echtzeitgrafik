#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h> // muss zuerst inkludiert werden
#include <GLFW/glfw3.h>

class Shader {
public:
    Shader();
    ~Shader();
    void use();

private:
    GLuint programId;
};

#endif // SHADER_HPP
