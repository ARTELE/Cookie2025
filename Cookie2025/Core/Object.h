#pragma once
#include "ThreadUtils.h"

using InstanceId = int;

namespace cookie
{
	namespace core
	{
		class Object
		{
			InstanceId instanceId = 0;
			virtual void InternalInitialize() = 0;
			virtual void InternalDestroy() = 0;
		public:
			void Initialize();
			void Destroy();
			InstanceId GetInstanceId() const { return instanceId; }
		};
	}
}
