#pragma once
#include <unordered_map>

namespace cookie
{
    namespace core
    {
        template <typename T = void, size_t Align = 0>
        class HeapAllocator
        {
            std::unordered_map<void*, size_t> memoryTable;
        public:

            template <typename T, typename... Args>
            T* Construct(Args&&... args)
            {
                T* obj = new T(std::forward<Args>(args)...);
                memoryTable.insert(std::make_pair(obj, sizeof(T)));
                return obj;
            }

            template <typename T>
            void Destroy(T* ptr)
            {
                if (ptr)
                {
                    if (!memoryTable.contains(ptr))
                    {
                        // Log Error
                        return;
                    }
                    ptr->~T();
                }
            }

            char* Allocate(size_t size)
            {
                return new char[size];
            }

            void Deallocate(char* ptr)
            {
                if (ptr)
                {
                    delete[] ptr;
                }
            }
        };
    }
}