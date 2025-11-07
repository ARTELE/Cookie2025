#include <iostream>
#include <fstream>
#include "Engine.h"
#include <Core/Serialize/Cereal.h>
#include <Platform/Platform.h>
#include <Core/Serialize/Allocator.h>
#include <Editor/Editor.h>


//struct Test
//{
//	uint16_t a;
//	uint32_t b;
//
//	template<typename T>
//	void serialize(T& ar)
//	{
//		ar(CEREAL_NVP(a), CEREAL_NVP(b));
//	}
//};
//
//int main()
//{
//	cookie::Engine engine;
//	engine.Initialize();
//
//	Test test{ 42, 1337 };
//	{
//		std::ofstream os("test.json");
//		cereal::JSONOutputArchive archive(os);
//		archive(cereal::make_nvp("Test", test));
//	}
//	{
//		std::ifstream is("test.json");
//		cereal::JSONInputArchive archive(is);
//		Test loadedTest;
//		archive(loadedTest);
//		std::cout << "Loaded Test: a=" << loadedTest.a << ", b=" << loadedTest.b << std::endl;
//	}
//
//	return 0;
//}

using namespace cookie;
// Main code
int main(int, char**)
{
    core::GenericAllocator allocator;
    platform::Windows windows;
    windows.Initialize();

    core::FrameContext context;
    editor::Editor editor;
    editor.Initialize();
    editor.Update(context);
    editor.Destroy();
    
    return 0;
}