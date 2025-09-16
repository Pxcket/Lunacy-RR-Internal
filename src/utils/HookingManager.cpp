#include "HookingManager.h"

inline MH_STATUS Ihooks::create(void* target, void* detour, void** orig) //cant wait to make an manager for other detour hooking, if we ever add it before leaking src
{
	MH_CreateHook(target, detour, orig);
	return MH_EnableHook(target);
}
