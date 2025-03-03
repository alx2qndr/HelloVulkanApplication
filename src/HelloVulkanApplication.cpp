#include "HelloVulkanApplication.hpp"

HelloVulkanApplication::HelloVulkanApplication()
{
    if (!window.create("Hello, Vulkan Application!", 640, 480))
    {
        throw std::runtime_error("Failed to create window!");
    }

    createInstance();

    while (window.isOpen())
    {
        window.pollEvents();
    }
}

void HelloVulkanApplication::createInstance()
{
    vk::ApplicationInfo appInfo;
    appInfo.pApplicationName   = "Hello, Vulkan Application!";
    appInfo.applicationVersion = vk::makeVersion(0, 1, 0);
    appInfo.pEngineName        = "Hello, Vulkan Engine";
    appInfo.apiVersion         = vk::makeApiVersion(0, 1, 2, 0);
    appInfo.pNext              = nullptr;

    uint32_t extensionsCount = 0;
    const char* const* extensionsNames = window.getInstanceExtensions(&extensionsCount);

    std::vector<const char*> extensions(extensionsNames, extensionsNames + extensionsCount);
    if (debug)
    {
        std::cout << "Extensions to be requested:" << std::endl;
        for (auto extensionsName : extensions)
        {
            std::cout << '\t' << extensionsName << std::endl;
        }
    }
}
