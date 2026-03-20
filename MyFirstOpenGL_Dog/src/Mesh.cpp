#include "Mesh.h"
#include <GL/glew.h>

Mesh::Mesh(const std::vector<float>& vertices, int vertexCount)
    : count(vertexCount) // Inicializa count con el parametro recibido
{
    // Generar 1 VAO y 1 VBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // El VAO recuerda todas las configuraciones
    // que hagamos a continuacion para reproducirlas al dibujar
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // convierte el VBO en el buffer activo

    // Sube los datos de vertices a la memoria de la GPU
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Le explica a OpenGL como interpretar los bytes que acabamos de subir
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0); // Activa el atributo 0
    glBindBuffer(GL_ARRAY_BUFFER, 0); // Desata el VBO
    glBindVertexArray(0); // Desata el VAO
}

void Mesh::draw() const {
    glBindVertexArray(VAO); // restaura toda la configuracion que grabamos en el constructor
    glDrawArrays(GL_TRIANGLES, 0, count); // Dibuja los triangulos empezando desde el vertice 0
}

Mesh::~Mesh() {
    // Libera la memoria en la GPU
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}