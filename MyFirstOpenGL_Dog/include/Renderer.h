#pragma once
#include "Mesh.h"
#include "ShaderProgram.h"

// Clase que controla el pipeline de render
class Renderer {
public:
    // Limpia el buffer de color
    void clear() const;

    // Activa un shader y dibuja un mesh
    void draw(const ShaderProgram& shader, const Mesh& mesh) const;
};