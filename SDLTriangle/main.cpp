#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <iostream>

const char *vSource = R"(#version 330 core
    in vec4 a_position;
    in vec3 a_color;
    out vec3 p_color;

    void main() {
        gl_Position = a_position;
        p_color = a_color;
    }
)";

const char *fSource = R"(#version 330 core
    precision highp float;
    in vec3 p_color;
    out vec4 color;

    void main() {
        color = vec4(p_color, 1.0);
    }
)";

unsigned int vShader, fShader, program, vao, vbo;
unsigned int frameCurrent, frameNext;
int laPosition, laColor;
int delta;
SDL_Window *window;
SDL_GLContext context;
float b[18] = {
    0.0, 0.8, 0.0, 1.0, 0.0, 0.0,
    -0.8, -0.8, 0.0, 0.0, 1.0, 0.0,
    0.8, -0.8, 0.0, 0.0, 0.0, 1.0
};
bool running = true;

void mainLoop();

int main(int argc, char *argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Failed to initialize!" << std::endl;
        return 0;
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    window = SDL_CreateWindow("Triangle Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    context = SDL_GL_CreateContext(window);
    gladLoadGLLoader(SDL_GL_GetProcAddress);
    std::cout << glGetString(GL_VERSION) << std::endl;

    // Initialize Shader
    vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vSource, 0);
    glCompileShader(vShader);
    fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fSource, 0);
    glCompileShader(fShader);
    program = glCreateProgram();
    glAttachShader(program, vShader);
    glAttachShader(program, fShader);
    glLinkProgram(program);

    laPosition = glGetAttribLocation(program, "a_position");
    laColor = glGetAttribLocation(program, "a_color");

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(b), b, GL_STATIC_DRAW);
    glVertexAttribPointer(laPosition, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(laPosition);
    glVertexAttribPointer(laColor, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) (3 * sizeof(float)));
    glEnableVertexAttribArray(laColor);

    // Loop Function
    mainLoop();

    return 0;
}

void mainLoop() {
    while (running) {
        frameCurrent = SDL_GetTicks();
        frameNext = frameCurrent + 16;
        delta = 16;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        glClearColor(0.0, 0.0, 0.0, 1.0);
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLineWidth(2);

        glUseProgram(program);
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        SDL_GL_SwapWindow(window);
        
        frameCurrent = SDL_GetTicks();
        //std::cout << frameNext - frameCurrent << std::endl;
        if (frameCurrent < frameNext) {
            SDL_Delay(frameNext - frameCurrent);
        }
    }
}
