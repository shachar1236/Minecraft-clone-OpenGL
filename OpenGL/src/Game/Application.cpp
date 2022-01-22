#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <glm/glm.hpp>
#include <iostream>
#include <string>

struct Shaders {
    std::string vertexShader;
    std::string fragmentShader;
};

static Shaders importShader(const std::string& filename)
{
    std::ifstream myFile(filename.c_str());
    std::string line;
    Shaders shaders = { "", "" };
    int type = 0;
    while (getline(myFile, line)) {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos) {
                type = 1;
            } else if (line.find("fragment") != std::string::npos) {
                type = 2;
            }
        } else {
            if (type == 1) {
                shaders.vertexShader += line + '\n';
            } else if (type == 2) {
                shaders.fragmentShader += line + '\n';
            }
        }
    }
    return shaders;
}

static unsigned int compileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Faild to compile shader " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
        std::cout << message << std::endl;

        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // setting v sync on
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) {
        return -1;
    }

    float positions[] = {
        -0.5f, -0.5f, 0.5f, //
        -0.5f, 0.5f, 0.5f, //
        0.5f, 0.5f, 0.5f, //
        0.5f, -0.5f, 0.5f //
    };

    unsigned int indecis[] = {
        0, 1, 2, // first triange
        2, 3, 0 // second triange
    };

    unsigned int buffer = 0;
    // genereting buffer
    glGenBuffers(1, &buffer);
    // binding buffer
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    // setting buffer data
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), positions, GL_STATIC_DRAW);

    // setting vertex attribute so the GPU will know how to draw
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    // setting vertex attribute so the GPU will know how to draw
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(8));

    // setting index buffer
    unsigned int ibo = 0;
    // genereting buffer
    glGenBuffers(1, &ibo);
    // binding buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    // setting buffer data
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indecis, GL_STATIC_DRAW);
    // importing shder from file
    Shaders source = importShader("res/shaders/Basic.shader");
    std::cout << source.vertexShader << std::endl;
    std::cout << source.fragmentShader << std::endl;

    // creating and compiling the shader
    unsigned int shader = createShader(source.vertexShader, source.fragmentShader);
    // using the shader
    glUseProgram(shader);
    // get uniform id
    // int location = glGetUniformLocation(shader, "u_Color");
    // if (location == -1) {
    //     std::cout << "Error: didnt find the uniform" << std::endl;
    //     return -1;
    // }
    float color_jump = 0.01f;
    float r = 0.0f;

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // set uniform value
        // glUniform4f(location, r, 0.8f, 0.4f, 1.0f);
        // r += color_jump;
        // if (r > 1.0f || r < 0.0f) {
        //     color_jump *= -1;
        // }
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    // deleting the shader
    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}
