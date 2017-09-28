#pragma once



#ifndef RT_APPLICTION_VULKAN
#define RT_APPLICTION_VULKAN



	//#include <cassert>
	#include <cstdint>
	#include <iostream>
	#include <stdexcept>
	#include <utility>
	#include <vector>

	#include "RT.Application\Header Files\Version.hpp"
	#include "RT.Application\Header Files\VulkanDeleter.hpp"



	#pragma region Graphics Libraries

	#if _WIN64
		#pragma comment(lib, SOLUTION_DIR"Externals\\VulkanSDK_1.0.26.0\\Bin64\\vulkan-1.lib")

		#if _DEBUG
			#pragma comment(lib, SOLUTION_DIR "Externals\\GLFW_BUILT\\64-bit\\D\\lib-vc2015\\glfw3.lib")
		#else
			#pragma comment(lib, SOLUTION_DIR "Externals\\GLFW_BUILT\\64-bit\\R\\lib-vc2015\\glfw3.lib")
		#endif
	#else
		#pragma comment(lib, SOLUTION_DIR"Externals\\VulkanSDK_1.0.26.0\\Bin32\\vulkan-1.lib")

		#if _DEBUG
			#pragma comment(lib, SOLUTION_DIR "Externals\\GLFW_BUILT\\32-bit\\D\\lib-vc2015\\glfw3.lib")
		#else
			#pragma comment(lib, SOLUTION_DIR "Externals\\GLFW_BUILT\\32-bit\\R\\lib-vc2015\\glfw3.lib")
		#endif
	#endif

	#pragma endregion Graphics Libraries



	#pragma region Graphics Headers

	#include "Externals\VulkanSDK_1.0.26.0\Include\vulkan\vulkan.h"
	#include "Externals\GLFW_BUILT\include\GLFW\glfw3.h"

	#pragma endregion Graphics Headers



	/*
	#define GLM_FORCE_RADIANS
	#define GLM_FORCE_DEPTH_ZERO_TO_ONE
	#include "Externals\GLM_0.9.8.1\glm\vec4.hpp"
	#include "Externals\GLM_0.9.8.1\glm\mat4x4.hpp"
	 */



	class Vulkan
	{
		public:
			#pragma region Constructors & Destructor

			/// <summary>
			/// </summary>
			Vulkan();

			/// <summary>
			/// </summary>
			Vulkan(const int16_t p_WIDTH, const int16_t p_HEIGHT);

			/// <summary>
			/// </summary>
			///
			/// <param name="p_vulkan">
			/// </param>
			Vulkan(const Vulkan& p_vulkan);

			/// <summary>
			/// </summary>
			///
			/// <param name="p_vulkan">
			/// </param>
			Vulkan operator=(Vulkan p_vulkan); // EXCEPTION SAFE

			/// <summary>
			/// </summary>
			~Vulkan();

			#pragma endregion Constructors & Desctructor



			/// <summary>
			/// </summary>
			void run();



		private:
			int16_t WIDTH;
			int16_t HEIGHT;

			GLFWwindow* window;

			VDeleter<VkInstance> instance { vkDestroyInstance };

			const std::vector<const char*> validationLayers = {"VK_LAYER_LUNARG_standard_validation"};

			#if _DEBUG
				//const bool enableValidationLayers = true;
				const bool enableValidationLayers = false;
			#else
				const bool enableValidationLayers = false;
			#endif



			/// <summary>
			/// </summary>
			bool checkValidationLayerSupport();

			/// <summary>
			/// </summary>
			void createInstance();

			/// <summary>
			/// </summary>
			std::vector<const char*> getRequiredExtensions();

			/// <summary>
			/// </summary>
			void initVulkan();

			/// <summary>
			/// </summary>
			void initWindow();

			/// <summary>
			/// </summary>
			void mainLoop();
	};
#endif