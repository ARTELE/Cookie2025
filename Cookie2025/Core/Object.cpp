#include "Object.h"

using namespace cookie::core;

void Object::Initialize()
{
	if (!ThreadUtils::IsMainThread())
	{
		//  Log Error
	}
	InternalInitialize();
}

void Object::Destroy()
{
	if (!ThreadUtils::IsMainThread())
	{
		//  Log Error
	}
	InternalDestroy();
}