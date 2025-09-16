#include "Movement.h"
#include <Windows.h>
#include <globals.hpp>
#include <HookingManager.h>
#include "../../../offsets.h"


typedef bool(__fastcall* tGetIsFlyingEnabled)(void* _this, void* method);
tGetIsFlyingEnabled get_IsFlyingEnabled_O = nullptr;
bool __fastcall get_IsFlyingEnabled_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Movement::dynamicFly)
        return true;

    return get_IsFlyingEnabled_O(instance, method);
}


typedef bool(__fastcall* tGetCanAggroEnemies)(void* _this, void* method);
tGetCanAggroEnemies get_CanAggroEnemies_O = nullptr;
bool __fastcall get_CanAggroEnemies_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Movement::Airstuck)
        return false;

    return get_CanAggroEnemies_O(instance, method);
}

typedef float(__fastcall* tGetMaxWalkSpeed)(void* _this, void* method);
tGetMaxWalkSpeed get_MaxWalkSpeed_O = nullptr;
float __fastcall get_MaxWalkSpeed_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Player::WalkSpeedT)
        return globals::Ihooks::RecRoom::Player::walkspeed;

    return get_MaxWalkSpeed_O(instance, method);
}


typedef float(__fastcall* tGetMaxSprintSpeed)(void* _this, void* method);
tGetMaxSprintSpeed get_MaxSprintSpeed_O = nullptr;
float __fastcall get_MaxSprintSpeed_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Player::WalkSpeedT)
        return globals::Ihooks::RecRoom::Player::walkspeed;

    return get_MaxSprintSpeed_O(instance, method);
}
void Movement::ApplyHooks()
{
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreLocomotion::PlayerMovement::get_IsFlyingEnabled), &get_IsFlyingEnabled_H, (void**)&get_IsFlyingEnabled_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreLocomotion::PlayerMovement::Airstuck), &get_CanAggroEnemies_H, (void**)&get_CanAggroEnemies_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreLocomotion::PlayerMovement::get_MaxWalkSpeed), &get_MaxWalkSpeed_H, (void**)&get_MaxWalkSpeed_O);
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::RecRoomCoreLocomotion::PlayerMovement::get_MaxSprintSpeed), &get_MaxSprintSpeed_H, (void**)&get_MaxSprintSpeed_O);
}