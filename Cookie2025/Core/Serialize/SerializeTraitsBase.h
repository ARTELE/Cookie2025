#pragma once

namespace cookie
{
	namespace core
	{
		template<typename T>
		class SerializeTraitsBase
		{
		public:
			static size_t GetSize() { return sizeof(T); }
		};

		template<typename T>
		class SerializeTraits : public SerializeTraitsBase<T>
		{
		public:
			static const char* GetTypeString() { return T::GetTypeString(); }
		};
	}
}