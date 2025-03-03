#pragma once

#include <iostream>
#include <vector>

#include <vulkan/vulkan.hpp>

#include "Window.hpp"

constexpr bool debug = true;

class HelloVulkanApplication
{
public:
    HelloVulkanApplication();
    ~HelloVulkanApplication() = default;

private:
    Window window;

    vk::Instance instance;

    void createInstance();
};