#pragma once
#include <cstddef>
#include <cstdint>
#include <new>
#include <type_traits>
#include <mimalloc.h>

namespace cookie
{
	namespace core
	{
		template <typename T = void, size_t Align = 0>
		class HeapAllocator
		{
		public:

			static void* Allocate(size_t size, size_t align = 0)
			{
				if (size == 0) return nullptr;

				const size_t actual_align = ResolveAlignment(align);
				void* ptr = mi_aligned_alloc(actual_align, size);
				if (!ptr) throw std::bad_alloc();
				return ptr;
			}

			static void Deallocate(void* ptr) noexcept
			{
				if (ptr)
				{
					mi_free(ptr);
				}
			}

			static void* Reallocate(void* old_ptr, size_t new_size, size_t align = 0)
			{
				if (new_size == 0)
				{
					Deallocate(old_ptr);
					return nullptr;
				}
				if (!old_ptr) return allocate(new_size, align);

				const size_t actual_align = ResolveAlignment(align);
				void* new_ptr = mi_realloc(old_ptr, new_size);

				if (new_ptr && !IsAligned(new_ptr, actual_align))
				{
					new_ptr = allocate(new_size, actual_align);
					std::memcpy(new_ptr, old_ptr, std::min(new_size, mi_usable_size(old_ptr)));
					Deallocate(old_ptr);
				}

				if (!new_ptr) throw std::bad_alloc();
				return new_ptr;
			}

			static size_t UsableSize(void* ptr) noexcept
			{
				return ptr ? mi_usable_size(ptr) : 0;
			}
		
		// STL
		public:
			using value_type = T;
			using pointer = T*;
			using const_pointer = const T*;
			using size_type = size_t;
			using difference_type = ptrdiff_t;

			template <typename U>
			struct rebind
			{
				static constexpr size_t NewAlign = std::max(Align, alignof(U));
				using other = HeapAllocator<U, NewAlign>;
			};

			HeapAllocator() noexcept = default;
			template <typename U, size_t A>
			HeapAllocator(const HeapAllocator<U, A>&) noexcept {}

			pointer allocate(size_type n)
			{
				constexpr size_t TypeAlign = alignof(T);
				constexpr size_t ActualAlign = std::max(Align, TypeAlign);
				static_assert(IsPowerOfTwo(ActualAlign), "Align must be a power of 2");
				return static_cast<pointer>(Allocate(n * sizeof(T), ActualAlign));
			}

			void deallocate(pointer p, size_type) noexcept
			{
				Deallocate(static_cast<void*>(p));
			}

			template <typename U, typename... Args>
			void construct(U* p, Args&&... args)
			{
				::new (static_cast<void*>(p)) U(std::forward<Args>(args)...);
			}

			template <typename U>
			void destroy(U* p) noexcept
			{
				p->~U();
			}

			friend bool operator==(const HeapAllocator&, const HeapAllocator&) noexcept
			{
				return true;
			}
			friend bool operator!=(const HeapAllocator&, const HeapAllocator&) noexcept
			{
				return false;
			}

		private:
			static constexpr bool IsPowerOfTwo(size_t x) noexcept
			{
				return x != 0 && (x & (x - 1)) == 0;
			}

			static bool IsAligned(const void* ptr, size_t align) noexcept
			{
				return (reinterpret_cast<uintptr_t>(ptr) % align) == 0;
			}

			static size_t ResolveAlignment(size_t align) noexcept
			{
				if (align != 0) return align;
				if constexpr (!std::is_same_v<T, void>) return alignof(T);
				return mi_get_default_alignment();
			}
		};

		template <typename T1, size_t A1, typename T2, size_t A2>
		bool operator==(const HeapAllocator<T1, A1>&, const HeapAllocator<T2, A2>&) noexcept
		{
			return true;
		}

		template <typename T1, size_t A1, typename T2, size_t A2>
		bool operator!=(const HeapAllocator<T1, A1>&, const HeapAllocator<T2, A2>&) noexcept
		{
			return false;
		}
	}
}