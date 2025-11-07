#pragma once
#include <memory>
#include <mimalloc.h>
#include <mimalloc-new-delete.h>

namespace cookie
{
	namespace core
	{

		#define STLAllocator mi_stl_allocator;

		class GenericAllocator
		{
		public:

			template <typename T>
			T* Allocate(size_t size, size_t align = 0)
			{
				return mi_malloc_aligned(size, align);
			}

			void Deallocate(void* p)
			{
				mi_free(p);
			}

			template <typename T>
			T* Reallocate(T* p, size_t size, size_t align = 0)
			{
				return mi_realloc_aligned(p, size, align);
			}

			template <typename T>
			T* AllocateArray(size_t count, size_t align = 0)
			{
				return mi_malloc_aligned(sizeof(T) * count, align);
			}

			template <typename T, typename... Args>
			T* Construct(Args&&... args)
			{
				return new T(std::forward<Args>(args)...);
			}

			template <typename T, typename... Args>
			T* ConstructArray(size_t count, Args&&... args)
			{
				return new T[count](std::forward<Args>(args)...);
			}
		};

		template <typename T>
		struct MiDeleter 
		{
			void operator()(T* ptr) const 
			{
				if (ptr != nullptr)
				{
					ptr->~T();
					mi_free(ptr);
				}
			}
		};

		template <typename T, typename... Args>
		std::shared_ptr<T> MakeMimallocShared(Args&&... args) 
		{
			void* memory = mi_malloc(sizeof(T));
			if (memory == nullptr) 
			{
				throw std::bad_alloc();
			}

			T* ptr = new (memory) T(std::forward<Args>(args)...);
			return std::shared_ptr<T>(ptr, MiDeleter<T>());
		}
	}
}