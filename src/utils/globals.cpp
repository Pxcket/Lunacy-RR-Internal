#include "globals.hpp"
#include <Windows.h>
namespace globals
{
	bool open = true;
	bool DiscordRPC = true;
	int tabs = 0;


	namespace Ihooks
	{
		namespace UnityEngine
		{
			namespace Camera
			{
				bool FOVChanger = false;
				float CustomFOV = 90.0f;
                float ZoomFOV = 20.0f;
                char ZoomKey = 'R';
                bool IsZoomed = false;
                float DefaultFOV = 90.0f;
                bool ZoomToggleMode = false;
			}
		}

		namespace RecRoom
		{





            namespace Weapon {
                bool AntiCooldown = false;
                bool InfiniteAmmo = false;
                bool OneHitKill = false;
                bool AimAssist = false;
                bool AutoFireEnabled = false;
                bool AntiRecoil = false;
                float CustomRecoilMultiplier = 0.0f;
                float MaximFiringRate = 50.0f;
                bool CustomFireRate = false;
                bool BulletToggle = false;
                int BulletAmount = 1;
                bool NoSpreadCheck = false;
                float NoSpreadValue = 0.0f;
                bool bulletspeecheck = false;
                float bulletspeed = 1.0f;
                float projectileLifetime = 1.0f;
                bool projectilelifecheck = false;
                bool HideShots = false;

            }



            namespace Anti
            {
                bool nopEveryRPC = false;
                bool nopOnEvent = false;
                bool nopCandles = false;
                bool nopCheerCrash = false;
                bool nopDespawnPlayer = false;
                bool nopLevelUpCrash = false;
            }


            namespace Movement
            {
                bool dynamicFly = false;
                bool Airstuck = false;
                bool Spinbot = false;
                float yawspin = 0.0f;
                float spinspeed = 15.0f;
                int AirstuckHotkey = VK_F10;
            }







            namespace Player {
                bool DevHook = false;
                bool QuestPlayerIsInvincible = false;
                bool InventionSpawnBypass = false;
                bool WhiteGloveCreator = false;
                bool TutorialBypass = false;
                bool OwnKeys = false;
                bool BypassHostOnlyAreas = false;
                bool WalkSpeedT = false;
                float walkspeed = 1.0f;
                bool BypassTrialItems = false;
                bool GodMode = false;
                bool CheckForBodyMovement = false;
                bool antiweapondrop = false;
            }





            namespace Quests {
                namespace Points {
                    bool QuestPointsModifier = false;
                    int QuestPointsInt = 1;
                    bool QuestGoldModifier = false;
                    bool JewishMoneyMode = false;
                    int QuestGoldInt = 1;
                }

                namespace Skip {
                    bool SkipGoldenTrophy = false;
                    bool SkipCrims = false;
                    bool SkipJumbotron = false;
                    bool SkipIsle = false;
                    bool SkipCresendo = false;
                    bool SkipBoss = false;
                    bool CustomSkip = false;
                    int CustomSkipper = 1;
                }
            }
            namespace Vehicle
            {
                bool HitBoxCheck = false;
                float HitboxSize = 1.0f;
                bool GetAllowBoosting = false;
                bool SyncedVehicleSpeedCheck = false;
				float SyncedVehicleSpeedValue = 1.0f;
				bool CurrentThrottleCheck = false;
				float CurrentThrottleValue = 1.0f;

            }
		}
	}
}