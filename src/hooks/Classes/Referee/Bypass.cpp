#include "Bypass.h"
#include <MinHook.h>
#include <HookingManager.h>
#include <cstdint>
#include "../../offsets.h"
#include <CMD.hpp>

typedef void(__fastcall* tRetHook)(void* _this);
tRetHook old_retHook = nullptr;
void __fastcall retHook_H(void* instance)
{
	return;
}

typedef void(__fastcall* tNotifyServer)(void* _this);
tNotifyServer old_notifyServer = nullptr;
void __fastcall notifyServer_H(void* instance)
{
	return;
}

typedef bool(__fastcall* tIsValid)(void* _this, void* targetUri, void* certs, void* methodInfo);
tIsValid IsValid_O = nullptr;
bool __fastcall IsValid_H(void* instance, void* targetUri, void* certs, void* methodInfo)
{
	return true;
}

typedef void(__fastcall* tFatalApplicationQuit)(void* _this, int32_t statusCode, void* message, void* methodInfo);
tFatalApplicationQuit FatalApplicationQuit_O = nullptr;
void __fastcall FatalApplicationQuit_H(void* instance, int32_t statusCode, void* message, void* methodInfo)
{
	return;
}

namespace Referee
{
	namespace NOPS
	{
		uintptr_t ref1 = 0x772130;// first offset aka the sub_
		uintptr_t ref2 = 0x760C90;// this is the 3rd sub_
		uintptr_t ref3 = 0x76F870;// this is the last sub_
	}
}


void Referee::Bypass() {
	MH_Initialize();


	Ihooks::create((void**)((uint64_t)GetModuleHandleA("Referee.dll") + Referee::NOPS::ref1), &retHook, (void**)&old_retHook);
	Ihooks::create((void**)((uint64_t)GetModuleHandleA("Referee.dll") + Referee::NOPS::ref2), &retHook, (void**)&old_retHook); //"shit gets patched on monday" head ass been 2 weeks already
	Ihooks::create((void**)((uint64_t)GetModuleHandleA("Referee.dll") + Referee::NOPS::ref3), &retHook, (void**)&old_retHook);

	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::obfuscated::IsValid), &IsValid_H, (void**)&IsValid_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::SessionManager::FatalApplicationQuit), &FatalApplicationQuit_H, (void**)&FatalApplicationQuit_O);


	CMD::success("if you see this they didnt fix anything, absolute brain dead devs :dingdong:\n");

}