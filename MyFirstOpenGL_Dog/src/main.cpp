#include "Window.h"
#include "Renderer.h"
#include "ShaderProgram.h"
#include "Mesh.h"
#include <GLFW/glfw3.h>
#include <vector>

int main() {
    Window window(800, 600, "perrito");
    Renderer renderer;

    ShaderProgram sCafe  ("shaders/basic.vert", "shaders/brown.frag");
    ShaderProgram sOscuro  ("shaders/basic.vert", "shaders/black.frag");

    std::vector<float> caraVerts = {
        //cachete izquierdo de la carita
        -0.24f, 0.24f, 0.0f, //punto de arriba, pegado a la orejita
        -0.68f, -0.16f, 0.0f, //punto del medio del cachete
        -0.28f, -0.55f, 0.0f,

        //parte izquierda del rectangulo de la carita
        -0.24f, 0.24f, 0.0f, //comparte con el punto alto del cachete izquierdo
        -0.28f, -0.55f, 0.0f, //comparte con el punto bajo del cachete izquierdo
        0.25f, -0.58f, 0.0f, //comparte con el punto bajo del cachete derecho

        //parte derecha del rectangulo de la carita
        0.24f, 0.24f, 0.0f, //comparte con el punto alto del cachete derecho
        0.25f, -0.58f, 0.0f, //comparte con el punto bajo del cachete derecho
        -0.24f, 0.24f, 0.0f, //comparte con el punto alto del cachete izquierdo

        //cachete derecho de la carita
        0.24f, 0.24f, 0.0f, //punto de arriba, pegado a la orejita
        0.68f, -0.16f, 0.0f, //punto del medio del cachete
        0.25f, -0.58f, 0.0f,
    };

    std::vector<float> orejaIzqVerts = {
        // triangulo grande de la orejita
        -0.64f, -0.12f, 0.0f,
        -0.67f, 0.55f, 0.0f,
        -0.27f, 0.21f, 0.0f,

        // punta de la orejita
        -0.67f, 0.55f, 0.0f,
        -0.91f, 0.26f, 0.0f,
        -0.66f, 0.18f, 0.0f,
    };

    std::vector<float> orejaDerVerts = {
        // triangulo grande de la orejita
        0.27f, 0.21f, 0.0f,
        0.67f, 0.55f, 0.0f,
        0.64f, -0.12f, 0.0f,

        // punta de la orejita
        0.67f, 0.56f, 0.0f,
        0.91f, 0.25f, 0.0f,
        0.66f, 0.17f, 0.0f,
    };

    std::vector<float> narizVerts = {
        -0.17f, -0.21f, 0.0f,
        0.00f, -0.37f, 0.0f,
        0.17f, -0.21f, 0.0f,
    };

    Mesh mCara   (caraVerts,      12); // 4 triangulos * 3 vertices
    Mesh mOrejaI (orejaIzqVerts,   6); 
    Mesh mOrejaD (orejaDerVerts,   6); 
    Mesh mNariz  (narizVerts,      3); 

    // loop principal
    while (!window.shouldClose()) {

        // salir con Escape
        if (window.isKeyPressed(GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(window.getNative(), true);

        renderer.clear();

        renderer.draw(sCafe,  mCara);
        renderer.draw(sCafe,  mOrejaI);
        renderer.draw(sCafe,  mOrejaD);

        renderer.draw(sOscuro,  mNariz);

        window.swapAndPoll();
    }
    return 0;
}