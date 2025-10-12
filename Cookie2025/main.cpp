#include <iostream>
#include "Engine.h"
#include <Core/Serialize/YAMLWrite.h>

struct Test
{
	uint16_t a;
	uint32_t b;

	static const char* GetTypeString()
	{
		return "Test";
	}

	template<typename T>
	void Serialize(T& serializer)
	{
		SERIALIZE(a);
		SERIALIZE(b);
	}
};

int main()
{
	cookie::Engine engine;
	engine.Initialize();

	cookie::core::YAMLWrite write;

	Test test;
	write.SerializeRoot(test);

	return 0;
}