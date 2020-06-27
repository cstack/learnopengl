#include "glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

void framebuffer_size_callback(GLFWwindow*, int, int);

int main() {
  glfwInit(); // GLFW handles windows, user input

  // glfwWindowHint docs:
  // https://www.glfw.org/docs/3.3/group__window.html 
  // Tell GLFW to use OpenGL version 3.3
  // Will fail if user does not have OpenGL 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  // We are using core, not immediate mode.
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // OSX requires using forewards-compatible contexts.
  // Must handle future versions of itself.
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow* window = glfwCreateWindow(
    800, // width
    600, // height
    "LearnOpenGL", // name
    NULL,
    NULL
  );

  if (window == NULL) {
    printf("Failed to create GLFW window\n");
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  // Tell GLAD how to look up functions
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    printf("Failed to initialize GLAD\n");
    return -1;
  }

  glViewport(
    0, // lower left x
    0, // lower left y
    800, //width
    600 // height
  );

  // Window resize callback
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  printf("Hello World\n");

  // Render loop
  // Continue until GLFW instructed to close
  // (if user exits window)
  while(!glfwWindowShouldClose(window)) {
    // We are done rendering to back buffer.
    // Swap with front buffer to update frame
    // instantaneously. The technique is called:
    // Double Buffer
    glfwSwapBuffers(window);

    // Check for events (keyboard, mouse, window size)
    // Update window state, then do callbacks
    glfwPollEvents();
  }

  printf("GLFW has been instructed to close\n");

  // clean up all GLFW resources that were allocated
  glfwTerminate();

  return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  printf("framebuffer_size_callback(%d, %d)\n", width, height);
  glViewport(0, 0, width, height);
}