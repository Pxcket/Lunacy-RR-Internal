#include "RangedWeapon.h"
#include <Windows.h>
#include <cstdint>
#include <globals.hpp>
#include <HookingManager.h>
#include "../../../offsets.h"
#include "../../../../vec3.h"

typedef bool(__fastcall* tRangedGetAimAssistEnabled)(void* _this, void* method);
tRangedGetAimAssistEnabled Ranged_get_AimAssistEnabled_O = nullptr;
bool __fastcall Ranged_get_AimAssistEnabled_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::AimAssist)
        return true;

    return Ranged_get_AimAssistEnabled_O(instance, method);
}

typedef float(__fastcall* tRangedGetCurrentRecoilMultiplier)(void* _this, void* method);
tRangedGetCurrentRecoilMultiplier Ranged_get_CurrentRecoilMultiplier_O = nullptr;
float __fastcall Ranged_get_CurrentRecoilMultiplier_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::AntiRecoil)
        return globals::Ihooks::RecRoom::Weapon::CustomRecoilMultiplier;

    return Ranged_get_CurrentRecoilMultiplier_O(instance, method);
}

typedef float(__fastcall* tRangedGetMaximumFiringRate)(void* _this, void* method);
tRangedGetMaximumFiringRate Ranged_get_MaximumFiringRate_O = nullptr;
float __fastcall Ranged_get_MaximumFiringRate_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::CustomFireRate)
        return globals::Ihooks::RecRoom::Weapon::MaximFiringRate;

    return Ranged_get_MaximumFiringRate_O(instance, method);
}

typedef float(__fastcall* tRangedGetMaximumAutomaticFiringRate)(void* _this, void* method);
tRangedGetMaximumAutomaticFiringRate Ranged_get_MaximumAutomaticFiringRate_O = nullptr;
float __fastcall Ranged_get_MaximumAutomaticFiringRate_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::CustomFireRate)
        return globals::Ihooks::RecRoom::Weapon::MaximFiringRate;

    return Ranged_get_MaximumAutomaticFiringRate_O(instance, method);
}

typedef bool(__fastcall* tRangedGetPersistentHasInfiniteAmmo)(void* _this, void* method);
tRangedGetPersistentHasInfiniteAmmo Ranged_get_PersistentHasInfiniteAmmo_O = nullptr;
bool __fastcall Ranged_get_PersistentHasInfiniteAmmo_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return true;

    return Ranged_get_PersistentHasInfiniteAmmo_O(instance, method);
}

typedef bool(__fastcall* tRangedGetHasInfiniteAmmo)(void* _this, void* method);
tRangedGetHasInfiniteAmmo Ranged_get_HasInfiniteAmmo_O = nullptr;
bool __fastcall Ranged_get_HasInfiniteAmmo_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return true;

    return Ranged_get_HasInfiniteAmmo_O(instance, method);
}

typedef bool(__fastcall* tRangedGetHasInfiniteReserveAmmunition)(void* _this, void* method);
tRangedGetHasInfiniteReserveAmmunition Ranged_get_HasInfiniteReserveAmmunition_O = nullptr;
bool __fastcall Ranged_get_HasInfiniteReserveAmmunition_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return true;

    return Ranged_get_HasInfiniteReserveAmmunition_O(instance, method);
}

typedef INT32(__fastcall* tRangedGetAmmunitionMagazineSize)(void* _this, void* method);
tRangedGetAmmunitionMagazineSize Ranged_get_AmmunitionMagazineSize_O = nullptr;
INT32 __fastcall Ranged_get_AmmunitionMagazineSize_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return 9999;

    return Ranged_get_AmmunitionMagazineSize_O(instance, method);
}

typedef bool(__fastcall* tRangedGetSupportsDisarmOrDisable)(void* _this, void* method);
tRangedGetSupportsDisarmOrDisable Ranged_get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion_O = nullptr;
bool __fastcall Ranged_get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return false;

    return Ranged_get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion_O(instance, method);
}

typedef void(__fastcall* tRangedFire)(void* _this, Vector3 velocity, float charge, void* method);
tRangedFire Ranged_Fire_O = nullptr;
void __fastcall Ranged_Fire_H(void* instance, Vector3 velocity, float charge, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::BulletToggle)
    {
        int Bullets = globals::Ihooks::RecRoom::Weapon::BulletAmount;
        for (int i = 0; i < Bullets - 1; ++i)
        {
            Ranged_Fire_O(instance, velocity, charge, method);
        }
    }
    Ranged_Fire_O(instance, velocity, charge, method);
}

typedef bool(__fastcall* tGetIsOnCooldown)(void* _this, void* method);
tGetIsOnCooldown get_IsOnCooldown_O = nullptr;
bool __fastcall get_IsOnCooldown_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::AntiCooldown)
        return false;

    return get_IsOnCooldown_O(instance, method);
}

typedef float(__fastcall* tGetCurrentProjectileSpeed)(void* _this, void* method);
tGetCurrentProjectileSpeed get_CurrentProjectileSpeed_O = nullptr;
float __fastcall get_CurrentProjectileSpeed_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::bulletspeecheck)
        return globals::Ihooks::RecRoom::Weapon::bulletspeed;

    return get_CurrentProjectileSpeed_O(instance, method);
}

typedef float(__fastcall* tGetDefaultProjectileSpeed)(void* _this, void* method);
tGetDefaultProjectileSpeed get_DefaultProjectileSpeed_O = nullptr;
float __fastcall get_DefaultProjectileSpeed_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::bulletspeecheck)
        return globals::Ihooks::RecRoom::Weapon::bulletspeed;

    return get_DefaultProjectileSpeed_O(instance, method);
}

typedef float(__fastcall* tNoSpread)(void* _this, bool someBool);
tNoSpread original_noSpread = nullptr;
float __fastcall noSpread_Hook(void* instance, bool someBool)
{
    if (!instance) {
        return original_noSpread(instance, someBool);
    }

    if (globals::Ihooks::RecRoom::Weapon::NoSpreadCheck) {
        return globals::Ihooks::RecRoom::Weapon::NoSpreadValue;
    }

    return original_noSpread(instance, someBool);
}

typedef void(__fastcall* tRpcFireShot)(void* _this, void* method);
tRpcFireShot RpcFireShot_O = nullptr;
void __fastcall RpcFireShot_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::HideShots || globals::Ihooks::RecRoom::Anti::nopEveryRPC)
        return;

    RpcFireShot_O(instance, method);
}

void RangedWeapon::ApplyHooks()
{
	Ihooks::create((void**)offsets::obfuscated::ScreenPlayerRangedWeaponAccuracySettings::noSpread, &noSpread_Hook, (void**)&original_noSpread);


	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::RangedWeapon::Fire), &Ranged_Fire_H, (void**)&Ranged_Fire_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::RangedWeapon::get_IsOnCooldown), &get_IsOnCooldown_H, (void**)&get_IsOnCooldown_O);
	//Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") +offsets::RecRoomCoreCombat::RangedWeapon::get_AimAssistEnabled), &Ranged_get_AimAssistEnabled_H, (void**)&Ranged_get_AimAssistEnabled_O); // not working or im just retarded
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::RangedWeapon::get_CurrentRecoilMultiplier), &Ranged_get_CurrentRecoilMultiplier_H, (void**)&Ranged_get_CurrentRecoilMultiplier_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::RangedWeapon::get_PersistentHasInfiniteAmmo), &Ranged_get_PersistentHasInfiniteAmmo_H, (void**)&Ranged_get_PersistentHasInfiniteAmmo_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::RangedWeapon::get_HasInfiniteAmmo), &Ranged_get_HasInfiniteAmmo_H, (void**)&Ranged_get_HasInfiniteAmmo_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::RangedWeapon::get_HasInfiniteReserveAmmunition), &Ranged_get_HasInfiniteReserveAmmunition_H, (void**)&Ranged_get_HasInfiniteReserveAmmunition_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::RangedWeapon::get_AmmunitionMagazineSize), &Ranged_get_AmmunitionMagazineSize_H, (void**)&Ranged_get_AmmunitionMagazineSize_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::RangedWeapon::get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion), &Ranged_get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion_H, (void**)&Ranged_get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::RangedWeapon::get_CurrentProjectileSpeed), &get_CurrentProjectileSpeed_H, (void**)&get_CurrentProjectileSpeed_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::RangedWeapon::get_DefaultProjectileSpeed), &get_DefaultProjectileSpeed_H, (void**)&get_DefaultProjectileSpeed_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::RangedWeapon::RpcFireShot), &RpcFireShot_H, (void**)&RpcFireShot_O);
}