#include <Graphics2D/GameContainer.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

GameContainer::GameContainer() 
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    width = 640;
    height = 480;
    window = nullptr;

    stateManager = new StateManager();
    graphics = new Graphics();
}

GameContainer::~GameContainer()
{
    delete stateManager;
    stateManager = nullptr;
    delete graphics;
    graphics = nullptr;
}

bool GameContainer::setWindowed(int width, int height)
{
    this->width = width;
    this->height = height;
    window = glfwCreateWindow(width, height, "Engine2D", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    return true;
}

bool GameContainer::setFullscreen(int width, int height)
{
    return false;
}

bool GameContainer::setBorderlessFullscreen()
{
    return false;
}

void GameContainer::start()
{
    std::cout << width << ", " << height << std::endl;
    graphics->init(width, height);
    stateManager->initAll(this);

    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        stateManager->update(0.0);

        graphics->setColor(0.0f, 0.0f, 0.0f, 0.0f);
        graphics->clear();
        stateManager->render(*graphics);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    graphics->destroy();
    glfwTerminate();
}

void GameContainer::exit()
{
    glfwSetWindowShouldClose(window, true);
}

void GameContainer::addState(State& state)
{
    stateManager->addState(&state);
}

void GameContainer::enterState(int id)
{
    stateManager->enterState(id);
}
