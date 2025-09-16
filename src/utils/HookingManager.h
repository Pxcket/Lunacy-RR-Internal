#pragma once
#include <MinHook.h>

namespace Ihooks
{
	extern inline MH_STATUS create(void* target, void* detour, void** orig);
}