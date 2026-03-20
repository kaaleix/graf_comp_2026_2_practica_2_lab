#pragma once
#include <vector>

// Clase Mesh. Para almacenar datos de vertices en la memoria de la GPU,
// configurar como estan organizados esos datos (VAO/VBO) y dibujar la geometria
class Mesh {
public:
    // - vertices: lista plana de floats (los vertices de la figura que se quiere dibujar)
    // - vertexCount: numero de vertices
    Mesh(const std::vector<float>& vertices, int vertexCount);

    // Le ordena a OpenGL que dibuje la geometria almacenada en esta Mesh
    void draw() const;

    // Libera VAO y VBO de la GPU
    ~Mesh();

private:
    unsigned int VAO; // (Vertex Array Object) recuerda como estan organizados los datos
    unsigned int VBO; // (Vertex Buffer Object) almacena los datos de vertices en la GPU
    int count;        // Cantidad de vertices a dibujar
};