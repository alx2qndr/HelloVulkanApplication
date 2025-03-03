#include "Window.hpp"

Window::Window(const std::string& title, const int width, const int height)
{
    create(title, width, height);
}

Window::~Window()
{
    SDL_Vulkan_UnloadLibrary();
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Window::create(const std::string& title, const int width, const int height)
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        std::cerr << "Failed to initialize! SDL error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (!SDL_Vulkan_LoadLibrary(nullptr))
    {
        std::cerr << "Failed to load Vulkan library! SDL error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);
    if (!window)
    {
        std::cerr << "Failed to create window! SDL error: " << SDL_GetError() << std::endl;
        return false;
    }

    running = true;

    return true;
}

const char* const* Window::getInstanceExtensions(uint32_t* count)
{
    return SDL_Vulkan_GetInstanceExtensions(count);
}

bool Window::isOpen() const
{
    return running;
}

void Window::pollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            running = false;
            break;

        default:
            break;
        }
    }
}
