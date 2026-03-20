#include "Renderer.h"
#include <GL/glew.h>

void Renderer::clear() const {
    glClearColor(0.15f, 0.15f, 0.2f, 1.0f); // define el color con que se borra la pantalla
    glClear(GL_COLOR_BUFFER_BIT); // realiza la limpieza del buffer de color
}

void Renderer::draw(const ShaderProgram& shader, const Mesh& mesh) const {
    shader.use();   // activa el shader program
    mesh.draw();    // dibuja la geometria
}