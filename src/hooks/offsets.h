#pragma once // Include guard
#include <cstdint>

namespace offsets
{
    namespace UnityEngine
    {
        namespace Camera
        {
            extern uintptr_t set_fieldOfView;
            extern uintptr_t get_fieldOfView;
            extern uintptr_t get_current;
        }
        namespace Transform
        {
            extern uintptr_t set_eulerAngles;
            extern uintptr_t set_localRotation;
        }
        namespace RectTransformUtility
        {
            extern uintptr_t WorldToScreenPoint;
        }
    }
    namespace RecRoomCoreCombat
    {
        namespace RangedWeapon
        {
            extern uintptr_t get_IsOnCooldown;
            extern uintptr_t Fire;
            extern uintptr_t get_CurrentRecoilMultiplier;
            extern uintptr_t get_MaximumFiringRate;
            extern uintptr_t get_MaximumAutomaticFiringRate;
            extern uintptr_t get_PersistentHasInfiniteAmmo;
            extern uintptr_t get_HasInfiniteAmmo;
            extern uintptr_t get_HasInfiniteReserveAmmunition;
            extern uintptr_t get_AmmunitionMagazineSize;
            extern uintptr_t get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion;
            extern uintptr_t get_CurrentProjectileSpeed;
            extern uintptr_t get_CurrentProjectileSpreadMultiplier;
            extern uintptr_t get_DefaultProjectileSpeed;
            extern uintptr_t RpcFireShot;
        }
        namespace Weapon
        {
            extern uintptr_t get_HasEnoughMagazineAmmunition;
            extern uintptr_t get_TotalAmmunition;
            extern uintptr_t get_Tool;
            extern uintptr_t get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion;
            extern uintptr_t get_HasCustomReserveAmmoBehavior;
            extern uintptr_t get_MagazineAmmunition;
            extern uintptr_t get_PrefabConfiguredAmmunitionMagazineSize;
            extern uintptr_t get_ReserveAmmunition;
            extern uintptr_t get_PersistentTotalAmmunition;
            extern uintptr_t get_MagazineAmmunitionNormalized;
            extern uintptr_t get_FullyLoaded;
            extern uintptr_t get_IsAmmoTotallyExhausted;
            extern uintptr_t get_HasInfiniteReserveAmmunition;
            extern uintptr_t ForceAmmunitionValuesOnSpawn;
        }
    }
    namespace RecRoomConsumable
    {
        namespace ConsumableManager
        {
            extern uintptr_t SpawnConsumableForLocalPlayer;
        }
    }
    namespace RecRoomCoreLocomotion
    {
        namespace PlayerMovement
        {
            extern uintptr_t get_IsFlyingEnabled;
            extern uintptr_t Airstuck;
            extern uintptr_t get_MaxWalkSpeed;
            extern uintptr_t get_MaxSprintSpeed;
        }
    }
    namespace CodeStageAntiCheatDetectors
    {
        namespace RRCheatDetector
        {
            extern uintptr_t StartDetection1;
            extern uintptr_t StartDetection2;
            extern uintptr_t StartDetection3;
            extern uintptr_t StartDetection4;
            extern uintptr_t StartDetection5;
        }
        namespace InjectionDetector
        {
            extern uintptr_t StartDetection1;
            extern uintptr_t StartDetection2;
        }
        namespace ObscuredCheatingDetector
        {
            extern uintptr_t StartDetection1;
            extern uintptr_t StartDetection2;
        }
        namespace SpeedHackDetector
        {
            extern uintptr_t StartDetection1;
            extern uintptr_t StartDetection2;
            extern uintptr_t StartDetection3;
            extern uintptr_t StartDetection4;
            extern uintptr_t StartDetection5;
        }
        namespace TimeCheatingDetector
        {
            extern uintptr_t StartDetection1;
            extern uintptr_t StartDetection2;
        }
        namespace WallHackDetector
        {
            extern uintptr_t StartDetection1;
            extern uintptr_t StartDetection2;
            extern uintptr_t StartDetection3;
            extern uintptr_t StartDetection4;
        }
    }
    namespace SessionManager
    {
        extern uintptr_t FatalApplicationQuit;
        extern uintptr_t get_IsDeveloper;
    }
    namespace Player
    {
        extern uintptr_t get_IsInitialized;
        extern uintptr_t SetHeadScale;
        extern uintptr_t get_RightHand;
        extern uintptr_t get_LeftHand;
        extern uintptr_t get_CurrentHeadPosition;
        extern uintptr_t get_CurrentBodyPosition;
        extern uintptr_t get_Head;
        extern uintptr_t get_Body;
        extern uintptr_t get_Ping;
        extern uintptr_t get_HardwareType;
        extern uintptr_t get_RecNetDeviceClass;
        extern uintptr_t GetFromActorNumber;
        extern uintptr_t get_IsInitialLoadFinished;
        extern uintptr_t RpcBroadcastDespawnPlayer;
        extern uintptr_t DoesLocalPlayerOwnKey;
        extern uintptr_t IsTrialItem;
        extern uintptr_t UpdateBodyAfterPlayerMovement;
        extern uintptr_t get_LocalPlayer;
        extern uintptr_t droptoolorsum;
        extern uintptr_t get_PlayerName;
    }
    namespace QuestManager
    {
        extern uintptr_t GetCurrentGameplayRoomIndex;
        extern uintptr_t RpcMasterAwardPoints;
        extern uintptr_t RpcMasterRequestAddLootAllPlayers;
        extern uintptr_t RpcMasterRequestAddLootSinglePlayer;
    }
    namespace GameCombatManager
    {
        extern uintptr_t PlayerIsInvincible;
    }
    namespace PlayerProgression
    {
        extern uintptr_t RpcPlayLevelUpFeedback;
        extern uintptr_t PlayCandlesFeedback;
        extern uintptr_t PlayCheerFeedback;
    }
    namespace PhotonPun
    {
        namespace PhotonView
        {
            extern uintptr_t get_ViewID;
            extern uintptr_t RPC;
            extern uintptr_t TransferOwnership;
        }
        namespace MonoBehaviourPun
        {
            extern uintptr_t get_PhotonView;
        }
    }
    namespace GroundVehicle
    {
        extern uintptr_t get_Speed;
        extern uintptr_t get_AllowsBoosting;
        extern uintptr_t get_SyncedVehicleSpeedOnForwardSigned;
        extern uintptr_t GetCurrentThrottle;
    }
    namespace obfuscated
    {
        extern uintptr_t IsValid;
        namespace photon
        {
            extern uintptr_t OnEvent;

            extern uintptr_t setMasterClient;
            extern uintptr_t get_isMasterClient;
            extern uintptr_t getActorNumber;

        }
        namespace ScreenPlayerRangedWeaponAccuracySettings
        {
            extern uintptr_t noSpread;
        }
    }
}
