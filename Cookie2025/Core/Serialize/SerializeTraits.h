#pragma once
#include "SerializeTraitsBase.h"
#include <cstdint>
namespace cookie
{
	namespace core
	{
		template<>
		class SerializeTraits<int32_t> : public SerializeTraitsBase<int32_t>
		{
		public:
			static const char* GetTypeString() { return "int32"; }
		};

		template<>
		class SerializeTraits<uint32_t> : public SerializeTraitsBase<uint32_t>
		{
		public:
			static const char* GetTypeString() { return "uint32"; }
		};

		template<>
		class SerializeTraits<int16_t> : public SerializeTraitsBase<int16_t>
		{
		public:
			static const char* GetTypeString() { return "int16"; }
		};

		template<>
		class SerializeTraits<uint16_t> : public SerializeTraitsBase<uint16_t>
		{
		public:
			static const char* GetTypeString() { return "uint16"; }
		};

		template<>
		class SerializeTraits<int64_t> : public SerializeTraitsBase<int64_t>
		{
		public:
			static const char* GetTypeString() { return "int64"; }
		};

		template<>
		class SerializeTraits<uint64_t> : public SerializeTraitsBase<uint64_t>
		{
		public:
			static const char* GetTypeString() { return "uint64"; }
		};

		template<>
		class SerializeTraits<float> : public SerializeTraitsBase<float>
		{
		public:
			static const char* GetTypeString() { return "float"; }
		};

		template<>
		class SerializeTraits<double> : public SerializeTraitsBase<double>
		{
		public:
			static const char* GetTypeString() { return "double"; }
		};
	}
}