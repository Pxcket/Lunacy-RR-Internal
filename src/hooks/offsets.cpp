#include <cstdint>
#include "offsets.h"

namespace offsets
{
	namespace UnityEngine {

		namespace Camera {
			uintptr_t set_fieldOfView = 0x9C095B0;
			uintptr_t get_fieldOfView = 0x9C08270;
			uintptr_t get_current = 0x9C08140;
		}
		namespace Transform
		{
			uintptr_t set_eulerAngles = 0x9C64AC0;
			uintptr_t set_localRotation = 0x9C64C70;
		}
		namespace RectTransformUtility {
			uintptr_t WorldToScreenPoint = 0x9E7A350;
		}

	}

	namespace RecRoomCoreCombat {
		namespace RangedWeapon {
			uintptr_t get_IsOnCooldown = 0x1F5C990;
			uintptr_t Fire = 0x1F53180;
			uintptr_t get_CurrentRecoilMultiplier = 0x1F5C4E0;
			uintptr_t get_MaximumFiringRate = 0x1F5CB30;
			uintptr_t get_MaximumAutomaticFiringRate = 0x1F5CAB0;
			uintptr_t get_PersistentHasInfiniteAmmo = 0x1F5CC30;
			uintptr_t get_HasInfiniteAmmo = 0x1F5C6F0;
			uintptr_t get_HasInfiniteReserveAmmunition = 0x1F5C730;
			uintptr_t get_AmmunitionMagazineSize = 0x1F5C030;
			uintptr_t get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion = 0x1F5CE70;
			uintptr_t get_CurrentProjectileSpeed = 0x1F5C3B0;
			uintptr_t get_CurrentProjectileSpreadMultiplier = 0x1F5C410;
			uintptr_t get_DefaultProjectileSpeed = 0x1D63B20;
			uintptr_t RpcFireShot = 0x1F58A70;
		}

		namespace Weapon {
			uintptr_t get_HasEnoughMagazineAmmunition = 0x1F65130;
			uintptr_t get_TotalAmmunition = 0x1F65480;
			uintptr_t get_Tool = 0xA9AB10;
			uintptr_t get_SupportsDisarmOrDisableOnTotalAmmunitionExhaustion = 0x1F5E6D0;
			uintptr_t get_HasCustomReserveAmmoBehavior = 0x1F65110;
			uintptr_t get_MagazineAmmunition = 0x1F65320;
			uintptr_t get_PrefabConfiguredAmmunitionMagazineSize = 0xAA0E10;
			uintptr_t get_ReserveAmmunition = 0x1F653F0;
			uintptr_t get_PersistentTotalAmmunition = 0x1F65370;
			uintptr_t get_MagazineAmmunitionNormalized = 0x1F65250;
			uintptr_t get_FullyLoaded = 0x1F65080;
			uintptr_t get_IsAmmoTotallyExhausted = 0x1F651F0;
			uintptr_t get_HasInfiniteReserveAmmunition = 0x1F61830;
			uintptr_t ForceAmmunitionValuesOnSpawn = 0x1F5F730;
		}
	}

	namespace RecRoomConsumable {
		namespace ConsumableManager {
			uintptr_t SpawnConsumableForLocalPlayer = 0xFF9FA0;
		}
	}

	namespace RecRoomCoreLocomotion {
		namespace PlayerMovement {
			uintptr_t get_IsFlyingEnabled = 0x19F53F0;
			uintptr_t Airstuck = 0xAB1660;  //Enemy.h
			uintptr_t get_MaxWalkSpeed = 0x19F5D50;
			uintptr_t get_MaxSprintSpeed = 0x19F5A80;
		}
	}

	namespace CodeStageAntiCheatDetectors {
		namespace RRCheatDetector {
			uintptr_t StartDetection1 = 0x24E3210;
			uintptr_t StartDetection2 = 0x24E2EB0;
			uintptr_t StartDetection3 = 0x24E2FA0;
			uintptr_t StartDetection4 = 0x24E3140;
			uintptr_t StartDetection5 = 0x24E3080;
		}

		namespace InjectionDetector {
			uintptr_t StartDetection1 = 0x31E0010;
			uintptr_t StartDetection2 = 0x31DFFB0;
		}

		namespace ObscuredCheatingDetector {
			uintptr_t StartDetection1 = 0x31E3E20;
			uintptr_t StartDetection2 = 0x31E3F20;
		}

		namespace SpeedHackDetector {
			uintptr_t StartDetection1 = 0x31E8670;
			uintptr_t StartDetection2 = 0x31E89A0;
			uintptr_t StartDetection3 = 0x31E8920; //Never heard of an anticheat :shrug:
			uintptr_t StartDetection4 = 0x31E88A0;
			uintptr_t StartDetection5 = 0x31E8830;
		}

		namespace TimeCheatingDetector {
			uintptr_t StartDetection1 = 0x31EA9C0;
			uintptr_t StartDetection2 = 0x31EABA0;
		}

		namespace WallHackDetector {
			uintptr_t StartDetection1 = 0x31EEBB0;
			uintptr_t StartDetection2 = 0x31EEDB0;
			uintptr_t StartDetection3 = 0x31EEB30;
			uintptr_t StartDetection4 = 0x31EED40;
		}
	}


	namespace SessionManager {
		uintptr_t FatalApplicationQuit = 0x2228DB0;
		uintptr_t get_IsDeveloper = 0x2231540;
	}

	namespace Player {
		uintptr_t get_IsInitialized = 0x215EAC0;
		uintptr_t SetHeadScale = 0x215A7C0;
		uintptr_t get_RightHand = 0xC17060;
		uintptr_t get_LeftHand = 0xAFC690;
		uintptr_t get_CurrentHeadPosition = 0x215DF10;
		uintptr_t get_CurrentBodyPosition = 0x215D8C0;
		uintptr_t get_Head = 0xB32580;
		uintptr_t get_Body = 0xB27BD0;
		uintptr_t get_Ping = 0x215FA40;
		uintptr_t get_HardwareType = 0x215E640;
		uintptr_t get_RecNetDeviceClass = 0x215FF90; //used these for making the esp, it worked but i removed it later on because rec room passes a Vector2 on a WorldToScreen func like some retards :skull:
		uintptr_t GetFromActorNumber = 0x2140F10;
		uintptr_t get_IsInitialLoadFinished = 0x215EA70;
		uintptr_t RpcBroadcastDespawnPlayer = 0x21590D0;
		uintptr_t DoesLocalPlayerOwnKey = 0xFB2CB0; 
		uintptr_t IsTrialItem = 0x1553360;
		uintptr_t UpdateBodyAfterPlayerMovement = 0x215B610;
		uintptr_t get_LocalPlayer = 0x215F5A0;
		uintptr_t droptoolorsum = 0x2187CB0; // search term >> "Tool* releasedTool" :skull: could maybe work or not idc and idk 
		uintptr_t get_PlayerName = 0x215FD20;

	}


	namespace QuestManager {
		uintptr_t GetCurrentGameplayRoomIndex = 0x1843600; //obfuscated one down below this :skull: 
		uintptr_t RpcMasterAwardPoints = 0x1844770;
		uintptr_t RpcMasterRequestAddLootAllPlayers = 0x1F272D0;
		uintptr_t RpcMasterRequestAddLootSinglePlayer = 0x1F274C0; // Jewish Mindset, doesnt work rn but maybe if you call it, honestly i dont have enough time, other project have priority
	}

	namespace GameCombatManager {
		uintptr_t PlayerIsInvincible = 0x22C8770; 
	}

	namespace PlayerProgression
	{
		uintptr_t RpcPlayLevelUpFeedback = 0x21C5340;
		uintptr_t PlayCandlesFeedback = 0x21C5130;
		uintptr_t PlayCheerFeedback = 0x21C51E0;
	}


	namespace PhotonPun {
		namespace PhotonView {
			uintptr_t get_ViewID = 0x10C0B10;
			uintptr_t RPC = 0x782F6F0; //currently not used, am i making an sdk? no, do i care, fuck no
			uintptr_t TransferOwnership = 0x7832630;
		}

		namespace MonoBehaviourPun {
			uintptr_t get_PhotonView = 0x7827720;
		}
	}
	namespace GroundVehicle
	{
		uintptr_t get_Speed = 0x17C6360;
		uintptr_t get_AllowsBoosting = 0x17C60A0;
		uintptr_t get_SyncedVehicleSpeedOnForwardSigned = 0x17C63C0;
		uintptr_t GetCurrentThrottle = 0x17C1990;
	}
	namespace obfuscated
	{
		uintptr_t IsValid = 0x803F8C0; //Bottom results both with the same regex
		// "bool\s+IsValid\s*\(\s*System::Uri\*\s+[A-Z]+[A-Z0-9]*,\s*Array<BestHTTP::SecureProtocol::Org::BouncyCastle::Asn1::X509::X509CertificateStructure\*>\*\s+[A-Z]+[A-Z0-9]*\)"


		namespace photon {

			// RRPhotonPlayer* AFLCFHLHEHB
			// PhotonPlayer* HINDKKDIENG         //UPDATE THESE SO ITS EASY
			// PhotonNetworking = MAIAOGJNMHO 

			uintptr_t OnEvent = 0x7803E90; // search -> "METHOD(void, (UnityEngine::GameObject*, bool, " in photon network class lmfao #BrainDeadDevs

			uintptr_t getActorNumber = 0x0; // \PhotonRealtime\__NO_NAMESPACE__\, first result of search term -> "METHOD(int32_t, (PhotonPlayer*,"
			uintptr_t get_isMasterClient = 0x773A460; // fifth result of search term -> "METHOD(bool, (PhotonPlayer*, MethodInfo*)" in the PhotonPlayer Class, uhm but rec room know has a new network layer so idk, couldnt care LMFAO
			uintptr_t setMasterClient = 0x7809410;  // search term -> "Method(bool, (RRPhotonPlayer*" PhotonNetwork class

		}
		namespace ScreenPlayerRangedWeaponAccuracySettings
		{
			uintptr_t noSpread = 0x18B7490; // most bottom one that passes a player pointer in ScreenPlayerRangedWeaponAccuracySettings.h
		}
	}


}
