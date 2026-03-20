#include "Window.h"
#include <iostream>

Window::Window(int width, int height, const std::string& title) {
    glfwInit(); // Inicializa la librería GLFW

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.x
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // OpenGL 3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // solo funciones modernas

    // Crea la ventana del OS con su contexto OpenGL
    handle = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!handle) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(handle);

    // Cada vez que cambie el tamaño de la ventana GLFW llamara a esta funcion
    glfwSetFramebufferSizeCallback(handle, framebufferSizeCallback);

    // Inicializa GLEW despues de tener un contexto OpenGL activo
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
    }
}

Window::~Window() {
    glfwTerminate(); // Libera todos los recursos de GLFW
}

bool Window::shouldClose() const {
    // Pregunta a GLFW si se marco esta ventana para cerrar
    return glfwWindowShouldClose(handle);
}

void Window::swapAndPoll() {
    glfwSwapBuffers(handle); // mientras mostramos un frame, dibujamos el siguiente en el otro buffer
    glfwPollEvents(); // Procesa todos los eventos pendientes del OS
}

bool Window::isKeyPressed(int key) const {
    return glfwGetKey(handle, key) == GLFW_PRESS;
}

GLFWwindow* Window::getNative() const {
    return handle;
}

void Window::framebufferSizeCallback(GLFWwindow*, int w, int h) {
    // Ajusta el viewport para que el area de dibujo cubra toda la ventana nueva
    glViewport(0, 0, w, h);
}