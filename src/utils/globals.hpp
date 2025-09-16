#pragma once
namespace globals
{
	extern bool open;
    extern bool DiscordRPC;
	extern int tabs;


	namespace Ihooks
	{
		namespace UnityEngine
		{
			namespace Camera
			{
				extern bool FOVChanger;
				extern float CustomFOV;
                extern float ZoomFOV;
                extern char ZoomKey;
                extern bool IsZoomed;
                extern float DefaultFOV;
                extern bool ZoomToggleMode;
			}
		}
        namespace RecRoom
        {
            namespace Weapon {
              extern bool AntiCooldown;
              extern bool InfiniteAmmo;
              extern bool OneHitKill;
              extern bool AimAssist;
              extern bool AutoFireEnabled;
              extern bool AntiRecoil;
              extern float CustomRecoilMultiplier;
              extern float MaximFiringRate;
              extern bool CustomFireRate;
              extern bool BulletToggle;
              extern int BulletAmount;
              extern bool NoSpreadCheck;
              extern float NoSpreadValue;
              extern bool bulletspeecheck;
              extern float bulletspeed;
              extern float projectileLifetime;
              extern bool projectilelifecheck;
              extern bool HideShots;
            }
            namespace Anti
            {
                extern bool nopEveryRPC;
                extern bool nopOnEvent;
                extern bool nopCandles;
                extern bool nopCheerCrash;
                extern bool nopDespawnPlayer;
                extern bool nopLevelUpCrash;
            }

            namespace Movement
            {
                extern bool dynamicFly;
                extern bool Airstuck;
                extern int AirstuckHotkey;
                extern bool Spinbot;
                extern float yawspin;
                extern float spinspeed;
                extern float spinspeed;

            }
            namespace Player {
                extern bool DevHook;
                extern bool QuestPlayerIsInvincible;
                extern bool InventionSpawnBypass;
                extern bool WhiteGloveCreator;
                extern bool TutorialBypass;
                extern bool OwnKeys;
                extern bool BypassHostOnlyAreas;
                extern bool WalkSpeedT;
                extern float walkspeed;
                extern bool BypassTrialItems;
                extern bool GodMode;
                extern bool CheckForBodyMovement;
                extern bool antiweapondrop;
            }

            namespace Quests {
                namespace Points {
                    extern bool QuestPointsModifier;
                    extern bool JewishMoneyMode;
                    extern int QuestPointsInt;
                    extern bool QuestGoldModifier;
                    extern int QuestGoldInt;
                }

                namespace Skip {
                    extern bool SkipGoldenTrophy;
                    extern bool SkipCrims;
                    extern bool SkipJumbotron;
                    extern bool SkipIsle;
                    extern bool SkipCresendo;
                    extern bool SkipBoss;
                    extern bool CustomSkip;
                    extern int CustomSkipper;
                }
            }
            namespace Vehicle
            {
               extern bool HitBoxCheck;
               extern float HitboxSize;
               extern bool GetAllowBoosting;
               extern bool SyncedVehicleSpeedCheck;
               extern float SyncedVehicleSpeedValue;
               extern bool CurrentThrottleCheck;
               extern float CurrentThrottleValue;
            }
        }
	}
}