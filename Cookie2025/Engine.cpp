#include "Engine.h"
#include <Core/ThreadUtils.h>
#include <mimalloc.h>
#include <mimalloc-new-delete.h>
using namespace cookie;

void Engine::Initialize()
{
	core::ThreadUtils::FetchMainThreadId();


}