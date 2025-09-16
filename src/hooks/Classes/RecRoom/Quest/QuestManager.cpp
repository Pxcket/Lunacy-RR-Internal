#include "QuestManager.h"
#include <Windows.h>
#include <cstdint>
#include <globals.hpp>
#include <HookingManager.h>
#include "../../../offsets.h"
#include "../../../../vec3.h"

typedef void(__fastcall* tRpcMasterAwardPoints)(void* _this, Vector3 vec, void* param1, int32_t int1, bool bool1, int32_t int2, bool bool2, void* method);
tRpcMasterAwardPoints RpcMasterAwardPoints_O = nullptr;
void __fastcall RpcMasterAwardPoints_H(void* instance, Vector3 vec, void* param1, int32_t int1, bool bool1, int32_t int2, bool bool2, void* method)
{
    if (globals::Ihooks::RecRoom::Quests::Points::QuestPointsModifier)
        return RpcMasterAwardPoints_O(instance, vec, param1, globals::Ihooks::RecRoom::Quests::Points::QuestPointsInt, bool1, globals::Ihooks::RecRoom::Quests::Points::QuestPointsInt, bool2, method);

    return RpcMasterAwardPoints_O(instance, vec, param1, int1, bool1, int2, bool2, method);
}


typedef void(__fastcall* tRpcMasterRequestAddLootAllPlayers)(void* _this, void* param1, void* param2, INT32 amount, void* method);
tRpcMasterRequestAddLootAllPlayers RpcMasterRequestAddLootAllPlayers_O = nullptr;
void __fastcall RpcMasterRequestAddLootAllPlayers_H(void* instance, void* param1, void* param2, INT32 amount, void* method)
{
    if (globals::Ihooks::RecRoom::Quests::Points::QuestGoldModifier)
        return RpcMasterRequestAddLootAllPlayers_O(instance, param1, param2, globals::Ihooks::RecRoom::Quests::Points::QuestGoldInt, method);

    return RpcMasterRequestAddLootAllPlayers_O(instance, param1, param2, amount, method);
}

typedef void(__fastcall* tRpcMasterRequestAddLootSinglePlayer)(void* _this, void* param1, void* param2, INT32 amount, void* method);
tRpcMasterRequestAddLootSinglePlayer RpcMasterRequestAddLootSinglePlayer_O = nullptr;
void __fastcall RpcMasterRequestAddLootSinglePlayer_H(void* instance, void* param1, void* param2, INT32 amount, void* method)
{
    if (globals::Ihooks::RecRoom::Quests::Points::JewishMoneyMode)
        return RpcMasterRequestAddLootSinglePlayer_O(instance, param1, param2, globals::Ihooks::RecRoom::Quests::Points::QuestGoldInt, method);

    return RpcMasterRequestAddLootSinglePlayer_O(instance, param1, param2, amount, method);
}


typedef INT32(__fastcall* tGetCurrentGameplayRoomIndex)(void* _this, void* method);
tGetCurrentGameplayRoomIndex GetCurrentGameplayRoomIndex_O = nullptr;
INT32 __fastcall GetCurrentGameplayRoomIndex_H(void* instance, void* method)
{
    if (globals::Ihooks::RecRoom::Quests::Skip::SkipGoldenTrophy)
        return INT32(9);
    else if (globals::Ihooks::RecRoom::Quests::Skip::SkipCrims)
        return INT32(9);
    else if (globals::Ihooks::RecRoom::Quests::Skip::SkipJumbotron)
        return INT32(9);
    else if (globals::Ihooks::RecRoom::Quests::Skip::SkipIsle)
        return INT32(7);
    else if (globals::Ihooks::RecRoom::Quests::Skip::SkipCresendo)
        return INT32(12);
    else if (globals::Ihooks::RecRoom::Quests::Skip::SkipBoss)
        return INT32(99);
    else if (globals::Ihooks::RecRoom::Quests::Skip::CustomSkip)
        return INT32(globals::Ihooks::RecRoom::Quests::Skip::CustomSkipper);

    return GetCurrentGameplayRoomIndex_O(instance, method);
}

void QuestManager::ApplyHooks()
{
	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::QuestManager::RpcMasterAwardPoints), &RpcMasterAwardPoints_H, (void**)&RpcMasterAwardPoints_O);

	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::QuestManager::RpcMasterRequestAddLootAllPlayers), &RpcMasterRequestAddLootAllPlayers_H, (void**)&RpcMasterRequestAddLootAllPlayers_O);

	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::QuestManager::RpcMasterRequestAddLootSinglePlayer), &RpcMasterRequestAddLootSinglePlayer_H, (void**)&RpcMasterRequestAddLootSinglePlayer_O);

	Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::QuestManager::GetCurrentGameplayRoomIndex), &GetCurrentGameplayRoomIndex_H, (void**)&GetCurrentGameplayRoomIndex_O);

}


//Jewish Mindset
/*
*	RVA: [0x1F274C0]
	void RpcMasterRequestAddLootSinglePlayer(RRNetworkPlayer* GLMBLPAKFLM, RecRoom::Core::GameManagement::LootTool* OMHLCDPMJKA, int32_t HGMAIPELJHM)
	{
		METHOD(void, (LootManager*, RRNetworkPlayer*, RecRoom::Core::GameManagement::LootTool*, int32_t, MethodInfo*), "System.Void RpcMasterRequestAddLootSinglePlayer(RRNetworkPlayer, RecRoom.Core.GameManagement.LootTool, System.Int32)");
		return function(this, GLMBLPAKFLM, OMHLCDPMJKA, HGMAIPELJHM, nullptr);
	}
*/