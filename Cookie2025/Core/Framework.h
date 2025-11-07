#pragma once
#include "FrameContext.h"
namespace cookie
{
	namespace core
	{
		class Framework
		{
		public:
			Framework() = default;
			virtual void Initialize() = 0;
			virtual void Update(FrameContext) = 0;
			virtual void Destroy() = 0;
			virtual ~Framework() = default;
		};
	}
}