#pragma once
#include "SerializeTraits.h"

namespace cookie
{
	namespace core
	{
		template<typename T>
		class SerializeBase
		{
			inline T& self() { return *((T*)(this)); }
		public:
			template<typename U>
			void SerializeRoot(U& data)
			{
				self().Serialize(data, SerializeTraits<U>::GetTypeString());
			}
		};
	}
}

#define SERIALIZE(x) serializer.Serialize(x, #x)
