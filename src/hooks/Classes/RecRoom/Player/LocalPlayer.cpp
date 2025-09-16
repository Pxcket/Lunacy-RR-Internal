#include <Windows.h>
#include <stdio.h>
#include <globals.hpp>
#include <HookingManager.h>
#include "../../../offsets.h"
#include "LocalPlayer.h"
#include <string>
#include "../../../../vec3.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// HELLO SKIDIES IF YOU SEE THIS U GAY - Pxcket
//Converts cs rec rooms a bitch
struct Quaternion
{
    float x, y, z, w; //Same with this bullshit
};
inline Quaternion EulerToQuaternion(float pitch, float yaw, float roll)
{

    const float DEG2RAD = 3.14159265f / 180.0f;
    float halfPitch = pitch * 0.5f * DEG2RAD;
    float halfYaw = yaw * 0.5f * DEG2RAD;
    float halfRoll = roll * 0.5f * DEG2RAD;
    float cp = cosf(halfPitch);
    float sp = sinf(halfPitch);
    float cy = cosf(halfYaw);
    float sy = sinf(halfYaw);
    float cr = cosf(halfRoll);
    float sr = sinf(halfRoll);
    Quaternion q;
    q.w = cr * cp * cy + sr * sp * sy; //Shit retard code but hey it works 
    q.x = sr * cp * cy - cr * sp * sy; //inspiration taken from https://stackoverflow.com/questions/31589901/euler-to-quaternion-quaternion-to-euler-using-eigen
    q.y = cr * sp * cy + sr * cp * sy; //Just basic math, make a seperate header file for it tho LFMAO
    q.z = cr * cp * sy - sr * sp * cy;

    return q;
}

#ifndef DWORD
typedef unsigned long DWORD;
#endif

struct Player
{
  // god i hate niggers, but we need to make unity calls asap. 
};




typedef void(__fastcall* tDropCurrentTool)(void* _this);
tDropCurrentTool DropCurrentTool_O = nullptr;
void __fastcall DropCurrentTool_H(void* releasedTool)
{
    if (globals::Ihooks::RecRoom::Player::antiweapondrop)
        return;

    DropCurrentTool_O(releasedTool);
}


typedef bool(__fastcall* tGetIsDeveloper)(void* _this);
tGetIsDeveloper get_IsDeveloper_O = nullptr;
bool __fastcall get_IsDeveloper_H(void* instance)
{
    if (globals::Ihooks::RecRoom::Player::DevHook)
        return true;

    return get_IsDeveloper_O(instance);
}


typedef bool(__fastcall* tPlayerIsInvincible)(void* _this, void* method);
tPlayerIsInvincible PlayerIsInvincible_O = nullptr;
bool __fastcall PlayerIsInvincible_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Player::QuestPlayerIsInvincible || globals::Ihooks::RecRoom::Player::GodMode)
        return true;

    return PlayerIsInvincible_O(instance, method);
}


typedef bool(__fastcall* tDoesLocalPlayerOwnKey)(void* _this, void* method);
tDoesLocalPlayerOwnKey DoesLocalPlayerOwnKey_O = nullptr;
bool __fastcall DoesLocalPlayerOwnKey_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Player::OwnKeys)
        return true;

    return DoesLocalPlayerOwnKey_O(instance, method);
}

typedef bool(__fastcall* tIsTrialItem)(void* _this, void* item, bool flag, void* method);
tIsTrialItem IsTrialItem_O = nullptr;
bool __fastcall IsTrialItem_H(void* instance, void* item, bool flag, void* method)
{
    if (globals::Ihooks::RecRoom::Player::BypassTrialItems)
        return false;

    return IsTrialItem_O(instance, item, flag, method);
}


typedef void(__fastcall* tUpdateBodyAfterPlayerMovement)(void* _this, void* method);
tUpdateBodyAfterPlayerMovement UpdateBodyAfterPlayerMovement_O = nullptr;
void __fastcall UpdateBodyAfterPlayerMovement_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Player::CheckForBodyMovement)
        return;

    UpdateBodyAfterPlayerMovement_O(instance, method);
}

void LocalPlayer::ApplyHooks()
{
    Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::SessionManager::get_IsDeveloper), &get_IsDeveloper_H, (void**)&get_IsDeveloper_O);
    Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::GameCombatManager::PlayerIsInvincible), &PlayerIsInvincible_H, (void**)&PlayerIsInvincible_O);
    Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::Player::DoesLocalPlayerOwnKey), &DoesLocalPlayerOwnKey_H, (void**)&DoesLocalPlayerOwnKey_O);
    Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::Player::IsTrialItem), &IsTrialItem_H, (void**)&IsTrialItem_O);
    Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::Player::UpdateBodyAfterPlayerMovement), &UpdateBodyAfterPlayerMovement_H, (void**)&UpdateBodyAfterPlayerMovement_O);
    Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::Player::droptoolorsum), &DropCurrentTool_H, (void**)&DropCurrentTool_O);
}