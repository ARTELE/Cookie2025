#include "ThreadUtils.h"
#include "CookieGlobals.h"

using namespace cookie::core;

bool ThreadUtils::IsMainThread()
{
	return mainThreadId == std::this_thread::get_id();
}

void ThreadUtils::FetchMainThreadId()
{
	mainThreadId = std::this_thread::get_id();
}