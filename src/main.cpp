#include <iostream>
#include <memory>

#include "HelloVulkanApplication.hpp"

int main(int argc, char **argv) 
{
    try
    {
        auto app = std::make_unique<HelloVulkanApplication>();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}