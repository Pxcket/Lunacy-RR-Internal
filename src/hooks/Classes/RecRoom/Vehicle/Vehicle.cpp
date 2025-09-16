#include "Vehicle.h"
#include <Windows.h>
#include <globals.hpp>
#include "../../../offsets.h"
#include <HookingManager.h>

typedef float(__fastcall* tGetSpeed)(void* _this, void* method);
tGetSpeed get_Speed_O = nullptr;
float __fastcall get_Speed_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Vehicle::HitBoxCheck)
        return globals::Ihooks::RecRoom::Vehicle::HitboxSize;

    return get_Speed_O(instance, method);
}


typedef bool(__fastcall* tGetAllowsBoosting)(void* _this, void* method);
tGetAllowsBoosting get_AllowsBoosting_O = nullptr;
bool __fastcall get_AllowsBoosting_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Vehicle::GetAllowBoosting)
        return true;

    return get_AllowsBoosting_O(instance, method);
}


typedef float(__fastcall* tGetSyncedVehicleSpeedOnForwardSigned)(void* _this, void* method);
tGetSyncedVehicleSpeedOnForwardSigned get_SyncedVehicleSpeedOnForwardSigned_O = nullptr;
float __fastcall get_SyncedVehicleSpeedOnForwardSigned_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Vehicle::SyncedVehicleSpeedCheck)
        return globals::Ihooks::RecRoom::Vehicle::SyncedVehicleSpeedValue;

    return get_SyncedVehicleSpeedOnForwardSigned_O(instance, method);
}


typedef float(__fastcall* tGetCurrentThrottle)(void* _this, void* method);
tGetCurrentThrottle GetCurrentThrottle_O = nullptr;
float __fastcall GetCurrentThrottle_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Vehicle::CurrentThrottleCheck)
        return globals::Ihooks::RecRoom::Vehicle::CurrentThrottleValue;

    return GetCurrentThrottle_O(instance, method);
}

void Vehicle::ApplyHooks()
{
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::GroundVehicle::get_Speed), &get_Speed_H, (void**)&get_Speed_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::GroundVehicle::get_AllowsBoosting), &get_AllowsBoosting_H, (void**)&get_AllowsBoosting_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::GroundVehicle::get_SyncedVehicleSpeedOnForwardSigned), &get_SyncedVehicleSpeedOnForwardSigned_H, (void**)&get_SyncedVehicleSpeedOnForwardSigned_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::GroundVehicle::GetCurrentThrottle), &GetCurrentThrottle_H, (void**)&GetCurrentThrottle_O);
}