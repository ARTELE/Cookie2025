#include <iostream>
#include <fstream>
#include "Engine.h"
#include <Core/Serialize/YAMLWrite.h>
#include <cereal/archives/json.hpp>

struct Test
{
	uint16_t a;
	uint32_t b;

	template<typename T>
	void serialize(T& ar)
	{
		ar(cereal::make_nvp("a", a), cereal::make_nvp("b", b));
	}
};

int main()
{
	cookie::Engine engine;
	engine.Initialize();

	Test test{ 42, 1337 };
	{
		std::ofstream os("test.json");
		cereal::JSONOutputArchive archive(os);
		archive(cereal::make_nvp("Test", test));
	}
	{
		std::ifstream is("test.json");
		cereal::JSONInputArchive archive(is);
		Test loadedTest;
		archive(loadedTest);
		std::cout << "Loaded Test: a=" << loadedTest.a << ", b=" << loadedTest.b << std::endl;
	}

	return 0;
}