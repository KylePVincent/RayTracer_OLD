#include "RT.Application\Header Files\Vulkan.hpp"



#pragma region Constructors & Destructor

Vulkan::Vulkan()
{
	WIDTH = (int16_t)960;
	HEIGHT = (int16_t)540;
}

Vulkan::Vulkan(const int16_t p_WIDTH, const int16_t p_HEIGHT)
{
	WIDTH = p_WIDTH;
	HEIGHT = p_HEIGHT;
}

Vulkan::Vulkan(const Vulkan& p_vulkan)
{
	WIDTH = p_vulkan.WIDTH;
	HEIGHT = p_vulkan.HEIGHT;
}

Vulkan Vulkan::operator=(Vulkan p_vulkan) // EXCEPTION SAFE
{
	std::swap(WIDTH, p_vulkan.WIDTH);
	std::swap(HEIGHT, p_vulkan.HEIGHT);

	return *this;
}

Vulkan::~Vulkan()
{
}

#pragma endregion Constructors & Destructor



#pragma region Public Methods

void Vulkan::run()
{
	initWindow();
	initVulkan();
	mainLoop();
}

#pragma endregion Public Methods



#pragma region Private Methods

bool Vulkan::checkValidationLayerSupport()
{
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : validationLayers)
	{
		bool layerFound = false;

		for (const auto& layerProperties : availableLayers)
		{
			if (strcmp(layerName, layerProperties.layerName) == 0)
			{
				layerFound = true;
				break;
			}
		}

		if (!layerFound)
		{
			return false;
		}
	}

	return true;
}

void Vulkan::createInstance()
{
	if ((enableValidationLayers) && (!checkValidationLayerSupport()))
	{
		throw std::runtime_error("Validation layers requested, but not available!");
	}

	// List the available Vulkan instance extensions for the current platform
	// being run on.
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
	std::vector<VkExtensionProperties> extensions(extensionCount);
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
	std::cout << "Available Vulkan Instance Extensions:" << std::endl;
	for (const auto& extension : extensions)
	{
		std::cout << "\t" << extension.extensionName << std::endl;
	}
	std::cout << std::endl;

	// Create Application Info struct
	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Ray Tracer";
	appInfo.applicationVersion = VK_MAKE_VERSION(RT_VERSION_MAJOR, RT_VERSION_MINOR, RT_VERSION_PATCH);
	appInfo.pEngineName = "NO ENGINE";
	appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	// Create Instance Info struct
	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;

	if (enableValidationLayers)
	{
		createInfo.enabledLayerCount = validationLayers.size();
		createInfo.ppEnabledLayerNames = validationLayers.data();
	}
	else
	{
		createInfo.enabledLayerCount = 0;
	}

	// List the Vulkan instance extensions required by GLFW.
	std::cout << "Vulkan Instance Extensions required by GLFW:" << std::endl;
	std::cout << "\t" << *glfwExtensions << std::endl << std::endl;

	// Create Vulkan instance
	if (vkCreateInstance(&createInfo, nullptr, instance.replace()) != VK_SUCCESS)
	{
		throw std::runtime_error("Failed to create instance!");
	}
}

std::vector<const char*> Vulkan::getRequiredExtensions()
{
	std::vector<const char*> extensions;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	for (uint32_t i = 0; i < glfwExtensionCount; ++i)
	{
		extensions.push_back(glfwExtensions[i]);
	}

	if (enableValidationLayers)
	{
		extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
	}

	return extensions;
}

void Vulkan::initVulkan()
{
	createInstance();
}

void Vulkan::initWindow()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow((int32_t)WIDTH, (int32_t)HEIGHT, "Vulkan", nullptr, nullptr);
}

void Vulkan::mainLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
}

#pragma endregion Private Methods