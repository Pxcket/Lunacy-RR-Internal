#include "AAC.h"
#include <HookingManager.h>
#include "../../../offsets.h"

typedef void(__fastcall* tRRCheatDetector_StartDetection1)(void* _this);
tRRCheatDetector_StartDetection1 RRCheatDetector_StartDetection1_O = nullptr;
void __fastcall RRCheatDetector_StartDetection1_H(void* instance)
{
	return;
}

typedef void(__fastcall* tRRCheatDetector_StartDetection2)(void* _this);
tRRCheatDetector_StartDetection2 RRCheatDetector_StartDetection2_O = nullptr;
void __fastcall RRCheatDetector_StartDetection2_H(void* instance)
{
	return;
}

typedef void(__fastcall* tRRCheatDetector_StartDetection3)(void* _this);
tRRCheatDetector_StartDetection3 RRCheatDetector_StartDetection3_O = nullptr;
void __fastcall RRCheatDetector_StartDetection3_H(void* instance)
{
	return;
}

typedef void(__fastcall* tRRCheatDetector_StartDetection4)(void* _this);
tRRCheatDetector_StartDetection4 RRCheatDetector_StartDetection4_O = nullptr;
void __fastcall RRCheatDetector_StartDetection4_H(void* instance)
{
	return;
}

typedef void(__fastcall* tRRCheatDetector_StartDetection5)(void* _this);
tRRCheatDetector_StartDetection5 RRCheatDetector_StartDetection5_O = nullptr;
void __fastcall RRCheatDetector_StartDetection5_H(void* instance)
{
	return;
}

typedef void(__fastcall* tInjectionDetector_StartDetection1)(void* _this);
tInjectionDetector_StartDetection1 InjectionDetector_StartDetection1_O = nullptr;
void __fastcall InjectionDetector_StartDetection1_H(void* instance)
{
	return;
}

typedef void(__fastcall* tInjectionDetector_StartDetection2)(void* _this);
tInjectionDetector_StartDetection2 InjectionDetector_StartDetection2_O = nullptr;
void __fastcall InjectionDetector_StartDetection2_H(void* instance)
{
	return;
}

typedef void(__fastcall* tObscuredCheatingDetector_StartDetection1)(void* _this);
tObscuredCheatingDetector_StartDetection1 ObscuredCheatingDetector_StartDetection1_O = nullptr;
void __fastcall ObscuredCheatingDetector_StartDetection1_H(void* instance)
{
	return;
}

typedef void(__fastcall* tObscuredCheatingDetector_StartDetection2)(void* _this);
tObscuredCheatingDetector_StartDetection2 ObscuredCheatingDetector_StartDetection2_O = nullptr;
void __fastcall ObscuredCheatingDetector_StartDetection2_H(void* instance)
{
	return;
}

typedef void(__fastcall* tSpeedHackDetector_StartDetection1)(void* _this);
tSpeedHackDetector_StartDetection1 SpeedHackDetector_StartDetection1_O = nullptr;
void __fastcall SpeedHackDetector_StartDetection1_H(void* instance)
{
	return;
}

typedef void(__fastcall* tSpeedHackDetector_StartDetection2)(void* _this);
tSpeedHackDetector_StartDetection2 SpeedHackDetector_StartDetection2_O = nullptr;
void __fastcall SpeedHackDetector_StartDetection2_H(void* instance)
{
	return;
}

typedef void(__fastcall* tSpeedHackDetector_StartDetection3)(void* _this);
tSpeedHackDetector_StartDetection3 SpeedHackDetector_StartDetection3_O = nullptr;
void __fastcall SpeedHackDetector_StartDetection3_H(void* instance)
{
	return;
}

typedef void(__fastcall* tSpeedHackDetector_StartDetection4)(void* _this);
tSpeedHackDetector_StartDetection4 SpeedHackDetector_StartDetection4_O = nullptr;
void __fastcall SpeedHackDetector_StartDetection4_H(void* instance)
{
	return;
}

typedef void(__fastcall* tSpeedHackDetector_StartDetection5)(void* _this);
tSpeedHackDetector_StartDetection5 SpeedHackDetector_StartDetection5_O = nullptr;
void __fastcall SpeedHackDetector_StartDetection5_H(void* instance)
{
	return;
}

typedef void(__fastcall* tTimeCheatingDetector_StartDetection1)(void* _this);
tTimeCheatingDetector_StartDetection1 TimeCheatingDetector_StartDetection1_O = nullptr;
void __fastcall TimeCheatingDetector_StartDetection1_H(void* instance)
{
	return;
}

typedef void(__fastcall* tTimeCheatingDetector_StartDetection2)(void* _this);
tTimeCheatingDetector_StartDetection2 TimeCheatingDetector_StartDetection2_O = nullptr;
void __fastcall TimeCheatingDetector_StartDetection2_H(void* instance)
{
	return;
}

typedef void(__fastcall* tWallHackDetector_StartDetection1)(void* _this);
tWallHackDetector_StartDetection1 WallHackDetector_StartDetection1_O = nullptr;
void __fastcall WallHackDetector_StartDetection1_H(void* instance)
{
	return;
}

typedef void(__fastcall* tWallHackDetector_StartDetection2)(void* _this);
tWallHackDetector_StartDetection2 WallHackDetector_StartDetection2_O = nullptr;
void __fastcall WallHackDetector_StartDetection2_H(void* instance)
{
	return;
}

typedef void(__fastcall* tWallHackDetector_StartDetection3)(void* _this);
tWallHackDetector_StartDetection3 WallHackDetector_StartDetection3_O = nullptr;
void __fastcall WallHackDetector_StartDetection3_H(void* instance)
{
	return;
}

typedef void(__fastcall* tWallHackDetector_StartDetection4)(void* _this);
tWallHackDetector_StartDetection4 WallHackDetector_StartDetection4_O = nullptr;
void __fastcall WallHackDetector_StartDetection4_H(void* instance)
{
	return;
}
void AntiAntiCheat::ApplyHooks()
{
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::RRCheatDetector::StartDetection1), &RRCheatDetector_StartDetection1_H, (void**)&RRCheatDetector_StartDetection1_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::RRCheatDetector::StartDetection2), &RRCheatDetector_StartDetection2_H, (void**)&RRCheatDetector_StartDetection2_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::RRCheatDetector::StartDetection3), &RRCheatDetector_StartDetection3_H, (void**)&RRCheatDetector_StartDetection3_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::RRCheatDetector::StartDetection4), &RRCheatDetector_StartDetection4_H, (void**)&RRCheatDetector_StartDetection4_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::RRCheatDetector::StartDetection5), &RRCheatDetector_StartDetection5_H, (void**)&RRCheatDetector_StartDetection5_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::InjectionDetector::StartDetection1), &InjectionDetector_StartDetection1_H, (void**)&InjectionDetector_StartDetection1_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::InjectionDetector::StartDetection2), &InjectionDetector_StartDetection2_H, (void**)&InjectionDetector_StartDetection2_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::ObscuredCheatingDetector::StartDetection1), &ObscuredCheatingDetector_StartDetection1_H, (void**)&ObscuredCheatingDetector_StartDetection1_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::ObscuredCheatingDetector::StartDetection2), &ObscuredCheatingDetector_StartDetection2_H, (void**)&ObscuredCheatingDetector_StartDetection2_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::SpeedHackDetector::StartDetection1), &SpeedHackDetector_StartDetection1_H, (void**)&SpeedHackDetector_StartDetection1_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::SpeedHackDetector::StartDetection2), &SpeedHackDetector_StartDetection2_H, (void**)&SpeedHackDetector_StartDetection2_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::SpeedHackDetector::StartDetection3), &SpeedHackDetector_StartDetection3_H, (void**)&SpeedHackDetector_StartDetection3_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::SpeedHackDetector::StartDetection4), &SpeedHackDetector_StartDetection4_H, (void**)&SpeedHackDetector_StartDetection4_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::SpeedHackDetector::StartDetection5), &SpeedHackDetector_StartDetection5_H, (void**)&SpeedHackDetector_StartDetection5_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::TimeCheatingDetector::StartDetection1), &TimeCheatingDetector_StartDetection1_H, (void**)&TimeCheatingDetector_StartDetection1_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::TimeCheatingDetector::StartDetection2), &TimeCheatingDetector_StartDetection2_H, (void**)&TimeCheatingDetector_StartDetection2_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::WallHackDetector::StartDetection1), &WallHackDetector_StartDetection1_H, (void**)&WallHackDetector_StartDetection1_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::WallHackDetector::StartDetection2), &WallHackDetector_StartDetection2_H, (void**)&WallHackDetector_StartDetection2_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::WallHackDetector::StartDetection3), &WallHackDetector_StartDetection3_H, (void**)&WallHackDetector_StartDetection3_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::CodeStageAntiCheatDetectors::WallHackDetector::StartDetection4), &WallHackDetector_StartDetection4_H, (void**)&WallHackDetector_StartDetection4_O);
}