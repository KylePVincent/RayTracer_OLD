#pragma once



#ifndef RT_APPLICATION_VULKANDELETER
#define RT_APPLICATION_VULKANDELETER



	#include <functional>

	#include "Externals\VulkanSDK_1.0.26.0\Include\vulkan\vulkan.h"



	template <typename T> class VDeleter
	{
		public:
			#pragma region Constructors & Destructor

			VDeleter() : VDeleter([](T, VkAllocationCallbacks*) {})
			{
			}

			VDeleter(std::function<void(T, VkAllocationCallbacks*)> deletef)
			{
				this->deleter = [=](T obj) {deletef(obj, nullptr); };
			}

			VDeleter(const VDeleter<VkInstance>& instance, std::function<void(VkInstance, T, VkAllocationCallbacks*)> deletef)
			{
				this->deleter = [&instance, deletef](T obj) { deletef(instance, obj, nullptr); };
			}

			VDeleter(const VDeleter<VkDevice>& device, std::function<void(VkDevice, T, VkAllocationCallbacks*)> deletef)
			{
				this->deleter = [&device, deletef](T obj) { deletef(device, obj, nullptr); };
			}

			~VDeleter()
			{
				cleanup();
			}

			#pragma endregion Constructors & Destructor



			const T* operator &() const
			{
				return &object;
			}

			T* replace()
			{
				cleanup();
				return &object;
			}

			operator T() const
			{
				return object;
			}

			void operator=(T rhs)
			{
				if (rhs != object)
				{
					cleanup();
					object = rhs;
				}
			}

			template<typename V> bool operator==(V rhs)
			{
				return object == T(rhs);
			}



		private:
			T object{ VK_NULL_HANDLE };
			std::function<void(T)> deleter;

			void cleanup()
			{
				if (object != VK_NULL_HANDLE)
				{
					deleter(object);
				}

				object = VK_NULL_HANDLE;
			}
	};



#endif