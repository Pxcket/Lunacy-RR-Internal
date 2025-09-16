#include "Weapon.h"
#include <Windows.h>
#include <cstdint>
#include <globals.hpp>
#include <HookingManager.h>
#include "../../../offsets.h"

typedef void(__fastcall* tForceAmmunitionValuesOnSpawn)(void* _this, int32_t ammo1, int32_t ammo2, void* method);
tForceAmmunitionValuesOnSpawn ForceAmmunitionValuesOnSpawn_O = nullptr;
void __fastcall ForceAmmunitionValuesOnSpawn_H(void* instance, int32_t ammo1, int32_t ammo2, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return ForceAmmunitionValuesOnSpawn_O(instance, 999, 999, method);

    return ForceAmmunitionValuesOnSpawn_O(instance, ammo1, ammo2, method);
}

typedef bool(__fastcall* tGetSupportsDisarmOrDisable)(void* _this, void* method);
tGetSupportsDisarmOrDisable get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion_O = nullptr;
bool __fastcall get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return false;

    return get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion_O(instance, method);
}

typedef bool(__fastcall* tGetHasCustomReserveAmmoBehavior)(void* _this, void* method);
tGetHasCustomReserveAmmoBehavior get_HasCustomReserveAmmoBehavior_O = nullptr;
bool __fastcall get_HasCustomReserveAmmoBehavior_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return true;

    return get_HasCustomReserveAmmoBehavior_O(instance, method);
}

typedef INT32(__fastcall* tGetMagazineAmmunition)(void* _this, void* method);
tGetMagazineAmmunition get_MagazineAmmunition_O = nullptr;
INT32 __fastcall get_MagazineAmmunition_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return 9999;

    return get_MagazineAmmunition_O(instance, method);
}

typedef INT32(__fastcall* tGetPrefabConfiguredAmmunitionMagazineSize)(void* _this, void* method);
tGetPrefabConfiguredAmmunitionMagazineSize get_PrefabConfiguredAmmunitionMagazineSize_O = nullptr;
INT32 __fastcall get_PrefabConfiguredAmmunitionMagazineSize_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return 9999;

    return get_PrefabConfiguredAmmunitionMagazineSize_O(instance, method);
}

typedef INT32(__fastcall* tGetAmmunitionMagazineSize)(void* _this, void* method);
tGetAmmunitionMagazineSize get_AmmunitionMagazineSize_O = nullptr;
INT32 __fastcall get_AmmunitionMagazineSize_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return 9999;

    return get_AmmunitionMagazineSize_O(instance, method);
}

typedef INT32(__fastcall* tGetReserveAmmunition)(void* _this, void* method);
tGetReserveAmmunition get_ReserveAmmunition_O = nullptr;
INT32 __fastcall get_ReserveAmmunition_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return 9999;

    return get_ReserveAmmunition_O(instance, method);
}

typedef INT32(__fastcall* tGetPersistentTotalAmmunition)(void* _this, void* method);
tGetPersistentTotalAmmunition get_PersistentTotalAmmunition_O = nullptr;
INT32 __fastcall get_PersistentTotalAmmunition_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return 9999;

    return get_PersistentTotalAmmunition_O(instance, method);
}

typedef INT32(__fastcall* tGetTotalAmmunition)(void* _this, void* method);
tGetTotalAmmunition get_TotalAmmunition_O = nullptr;
INT32 __fastcall get_TotalAmmunition_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return 9999;

    return get_TotalAmmunition_O(instance, method);
}

typedef float(__fastcall* tGetMagazineAmmunitionNormalized)(void* _this, void* method);
tGetMagazineAmmunitionNormalized get_MagazineAmmunitionNormalized_O = nullptr;
float __fastcall get_MagazineAmmunitionNormalized_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return 999.0f;

    return get_MagazineAmmunitionNormalized_O(instance, method);
}

typedef bool(__fastcall* tGetHasEnoughMagazineAmmunition)(void* _this, void* method);
tGetHasEnoughMagazineAmmunition get_HasEnoughMagazineAmmunition_O = nullptr;
bool __fastcall get_HasEnoughMagazineAmmunition_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return true;

    return get_HasEnoughMagazineAmmunition_O(instance, method);
}

typedef bool(__fastcall* tGetFullyLoaded)(void* _this, void* method);
tGetFullyLoaded get_FullyLoaded_O = nullptr;
bool __fastcall get_FullyLoaded_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return true;

    return get_FullyLoaded_O(instance, method);
}

typedef bool(__fastcall* tGetIsAmmoTotallyExhausted)(void* _this, void* method);
tGetIsAmmoTotallyExhausted get_IsAmmoTotallyExhausted_O = nullptr;
bool __fastcall get_IsAmmoTotallyExhausted_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return false;

    return get_IsAmmoTotallyExhausted_O(instance, method);
}

typedef bool(__fastcall* tGetHasInfiniteReserveAmmunition)(void* _this, void* method);
tGetHasInfiniteReserveAmmunition get_HasInfiniteReserveAmmunition_O = nullptr;
bool __fastcall get_HasInfiniteReserveAmmunition_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Weapon::InfiniteAmmo)
        return true;

    return get_HasInfiniteReserveAmmunition_O(instance, method);
}

void Weapon::ApplyHooks()
{

	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::Weapon::get_HasEnoughMagazineAmmunition), &get_HasEnoughMagazineAmmunition_H, (void**)&get_HasEnoughMagazineAmmunition_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::Weapon::get_TotalAmmunition), &get_TotalAmmunition_H, (void**)&get_TotalAmmunition_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::Weapon::ForceAmmunitionValuesOnSpawn), &ForceAmmunitionValuesOnSpawn_H, (void**)&ForceAmmunitionValuesOnSpawn_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::Weapon::get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion), &get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion_H, (void**)&get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::Weapon::get_HasCustomReserveAmmoBehavior), &get_HasCustomReserveAmmoBehavior_H, (void**)&get_HasCustomReserveAmmoBehavior_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::Weapon::get_PrefabConfiguredAmmunitionMagazineSize), &get_PrefabConfiguredAmmunitionMagazineSize_H, (void**)&get_PrefabConfiguredAmmunitionMagazineSize_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::Weapon::get_MagazineAmmunition), &get_MagazineAmmunition_H, (void**)&get_MagazineAmmunition_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::Weapon::get_ReserveAmmunition), &get_ReserveAmmunition_H, (void**)&get_ReserveAmmunition_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::Weapon::get_MagazineAmmunitionNormalized), &get_MagazineAmmunitionNormalized_H, (void**)&get_MagazineAmmunitionNormalized_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::Weapon::get_FullyLoaded), &get_FullyLoaded_H, (void**)&get_FullyLoaded_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::Weapon::get_IsAmmoTotallyExhausted), &get_IsAmmoTotallyExhausted_H, (void**)&get_IsAmmoTotallyExhausted_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreCombat::Weapon::get_HasInfiniteReserveAmmunition), &get_HasInfiniteReserveAmmunition_H, (void**)&get_HasInfiniteReserveAmmunition_O);

}
