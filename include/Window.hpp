#pragma once

#include <iostream>
#include <string>

#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>

class Window
{
public:
    Window() = default;
    Window(const std::string& title, int width, int height);

    ~Window();

    bool create(const std::string& title, int width, int height);

    const char* const* getInstanceExtensions(uint32_t* count);

    bool isOpen() const;

    void pollEvents();

private:
    SDL_Window* window = nullptr;

    bool running = false;

};