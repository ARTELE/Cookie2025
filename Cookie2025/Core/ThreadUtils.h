#pragma once
#include <thread>

namespace cookie
{
	namespace core
	{
		class ThreadUtils
		{
			inline static std::thread::id mainThreadId;
		public:
			static void FetchMainThreadId();
			static bool IsMainThread();
		};
	}
}