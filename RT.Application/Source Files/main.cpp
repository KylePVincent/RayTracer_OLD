#include "RT.Application\Header Files\main.hpp"



int32_t main(int32_t argc, char** argv)
{
	Vulkan VulkanApp;

	try
	{
		VulkanApp.run();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}