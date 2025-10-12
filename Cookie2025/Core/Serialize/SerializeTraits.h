#pragma once
#include "SerializeTraitsBase.h"
#include <cstdint>
namespace cookie
{
	namespace core
	{
		template<>
		class SerializeTraits<int32_t> : public SerializeTraitsBuiltInType<int32_t>
		{
		public:
			static const char* GetTypeString() { return "int32"; }
		};

		template<>
		class SerializeTraits<uint32_t> : public SerializeTraitsBuiltInType<uint32_t>
		{
		public:
			static const char* GetTypeString() { return "uint32"; }
		};

		template<>
		class SerializeTraits<int16_t> : public SerializeTraitsBuiltInType<int16_t>
		{
		public:
			static const char* GetTypeString() { return "int16"; }
		};

		template<>
		class SerializeTraits<uint16_t> : public SerializeTraitsBuiltInType<uint16_t>
		{
		public:
			static const char* GetTypeString() { return "uint16"; }
		};

		template<>
		class SerializeTraits<int64_t> : public SerializeTraitsBuiltInType<int64_t>
		{
		public:
			static const char* GetTypeString() { return "int64"; }
		};

		template<>
		class SerializeTraits<uint64_t> : public SerializeTraitsBuiltInType<uint64_t>
		{
		public:
			static const char* GetTypeString() { return "uint64"; }
		};

		template<>
		class SerializeTraits<float> : public SerializeTraitsBuiltInType<float>
		{
		public:
			static const char* GetTypeString() { return "float"; }
		};

		template<>
		class SerializeTraits<double> : public SerializeBase<double>
		{
		public:
			static const char* GetTypeString() { return "double"; }
		};
	}
}