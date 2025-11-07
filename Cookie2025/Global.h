#pragma once
#include <SDL3/SDL.h>

namespace cookie
{
	namespace global
	{
		class GlobalContext
		{
		public:
			inline static SDL_Window* window = nullptr;
			inline static SDL_GPUDevice* gpuDevice = nullptr;
			inline static float mainScale = 1.0f;
		};
	}
}