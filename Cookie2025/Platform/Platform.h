#pragma once
#include <SDL3/SDL.h>

namespace cookie
{
	namespace platform
	{
		class Platform
		{
		protected:
			virtual void CreateWindow() = 0;
			virtual void InitializeGraphicsContext() = 0;
		public:
			void Initialize();
		};

		class Windows : public Platform
		{
			virtual void InitializeGraphicsContext() override;
			virtual void CreateWindow() override;
		public:
		};
	}
}