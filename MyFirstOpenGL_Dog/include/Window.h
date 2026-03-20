#pragma once
#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <string>

// Clase que se encarga de todo lo que tiene que ver con la ventana del sistema operativo 
// y la inicializacion de OpenGL
class Window {
public:
    // Inicializa GLFW, crea la ventana y también inicializa GLEW
    Window(int width, int height, const std::string& title);

    ~Window();

    // Regresa true cuando el usuario cierra la ventana
    bool shouldClose() const;

    // Muestra el frame que acabamos de dibujar y procesa eventos del OS
    void swapAndPoll();

    // Consulta si una tecla está presionada en este frame
    bool isKeyPressed(int key) const;

    // Expone el puntero nativo por si se necesita para funciones de GLFW directamente
    GLFWwindow* getNative() const;

private:
    GLFWwindow* handle; // Puntero interno de GLFW a la ventana

    // callbacks de GLFW
    static void framebufferSizeCallback(GLFWwindow* w, int width, int height);
};