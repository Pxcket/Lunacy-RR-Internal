#include "RPC.h"
#include <Windows.h>
#include <globals.hpp>
#include "../../offsets.h"
#include <HookingManager.h>

typedef void(__fastcall* tRpcPlayLevelUpFeedback)(void* _this);
tRpcPlayLevelUpFeedback RpcPlayLevelUpFeedback_O = nullptr;
void __fastcall RpcPlayLevelUpFeedback_H(void* instance)
{
    if (globals::Ihooks::RecRoom::Anti::nopEveryRPC || globals::Ihooks::RecRoom::Anti::nopLevelUpCrash)
        return;

    RpcPlayLevelUpFeedback_O(instance);
}


typedef void(__fastcall* tRpcBroadcastDespawnPlayer)(void* _this);
tRpcBroadcastDespawnPlayer RpcBroadcastDespawnPlayer_O = nullptr;
void __fastcall RpcBroadcastDespawnPlayer_H(void* instance)
{
    if (globals::Ihooks::RecRoom::Anti::nopEveryRPC || globals::Ihooks::RecRoom::Anti::nopDespawnPlayer)
        return;

    RpcBroadcastDespawnPlayer_O(instance);
}


typedef void(__fastcall* tPlayCandlesFeedback)(void* _this);
tPlayCandlesFeedback PlayCandlesFeedback_O = nullptr;
void __fastcall PlayCandlesFeedback_H(void* instance)
{
    if (globals::Ihooks::RecRoom::Anti::nopEveryRPC || globals::Ihooks::RecRoom::Anti::nopCandles)
        return;

    PlayCandlesFeedback_O(instance);
}


typedef void(__fastcall* tPlayCheerFeedback)(void* _this);
tPlayCheerFeedback PlayCheerFeedback_O = nullptr;
void __fastcall PlayCheerFeedback_H(void* instance)
{
    if (globals::Ihooks::RecRoom::Anti::nopEveryRPC || globals::Ihooks::RecRoom::Anti::nopCheerCrash)
        return;

    PlayCheerFeedback_O(instance);
}


typedef void(__fastcall* tOnEvent)(void* _this);
tOnEvent OnEvent_O = nullptr;
void __fastcall OnEvent_H(void* instance)
{
    if (globals::Ihooks::RecRoom::Anti::nopEveryRPC || globals::Ihooks::RecRoom::Anti::nopOnEvent)
        return;

    OnEvent_O(instance);
}

void RPCs::ApplyHooks()
{

	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::PlayerProgression::RpcPlayLevelUpFeedback), &RpcPlayLevelUpFeedback_H, (void**)&RpcPlayLevelUpFeedback_O);

	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::Player::RpcBroadcastDespawnPlayer), &RpcBroadcastDespawnPlayer_H, (void**)&RpcBroadcastDespawnPlayer_O);

	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::PlayerProgression::PlayCandlesFeedback), &PlayCandlesFeedback_H, (void**)&PlayCandlesFeedback_O);

	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::PlayerProgression::PlayCheerFeedback), &PlayCheerFeedback_H, (void**)&PlayCheerFeedback_O);

	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::obfuscated::photon::OnEvent), &OnEvent_H, (void**)&OnEvent_O);

}