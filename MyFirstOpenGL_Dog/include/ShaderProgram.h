#pragma once
#include <string>

// Clase que toma los archivos de texto .vert y .frag y los convierte en codigo ejecutable para la GPU
// te da un objeto que puedes activar antes de dibujar
class ShaderProgram {
public:
    unsigned int ID; // el ID del programa en OpenGL

    // recibe las rutas a los dos archivos
    ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);

    // Activa este shader para el siguiente draw call
    void use() const;

    // Limpieza
    ~ShaderProgram();

private:
    // lee el contenido de un archivo y lo devuelve como string
    std::string readFile(const std::string& filePath) const;

    // compila un shader individual y regresa su ID
    unsigned int compileShader(const std::string& source, unsigned int type) const;
};