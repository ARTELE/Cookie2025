#include "Engine.h"
#include <Core/ThreadUtils.h>

using namespace cookie;

void Engine::Initialize()
{
	core::ThreadUtils::FetchMainThreadId();
}