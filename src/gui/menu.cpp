#include <Windows.h>
#include "menu.h"
#include "../dependencies/imgui/imgui.h"
#include "../utils/globals.hpp"
#include "../resources/Themes/Themes.h"
#include "../dependencies/kiero/kiero.h"
#include <vector>
#include <string>
#include "../dependencies/Config/Config.h"



// Please Recode This to be not all in one file, its just ugly and not good to overview.
static const char* keys[] = { "R", "Z", "Middle Mouse", "Shift", "Ctrl", "NONE" };
static int current_key = 0;

static const char* hotkey_options[] = { 
    "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12",
    "Left Alt", "Right Alt", "Left Ctrl", "Right Ctrl", "Left Shift", "Right Shift",
    "Tab", "Caps Lock", "Space", "Enter", "Backspace", "Delete", "Insert", "Home", "End",
    "Page Up", "Page Down", "Num 0", "Num 1", "Num 2", "Num 3", "Num 4", "Num 5", "Num 6", "Num 7", "Num 8", "Num 9"
};
static int current_hotkey = 0;

int GetHotkeyFromIndex(int index) { 
    switch (index) {
        case 0: return VK_F1; case 1: return VK_F2; case 2: return VK_F3; case 3: return VK_F4;
        case 4: return VK_F5; case 5: return VK_F6; case 6: return VK_F7; case 7: return VK_F8;
        case 8: return VK_F9; case 9: return VK_F10; case 10: return VK_F11; case 11: return VK_F12;
        case 12: return VK_LMENU; case 13: return VK_RMENU; case 14: return VK_LCONTROL; case 15: return VK_RCONTROL;
        case 16: return VK_LSHIFT; case 17: return VK_RSHIFT; case 18: return VK_TAB; case 19: return VK_CAPITAL;
        case 20: return VK_SPACE; case 21: return VK_RETURN; case 22: return VK_BACK; case 23: return VK_DELETE;
        case 24: return VK_INSERT; case 25: return VK_HOME; case 26: return VK_END; case 27: return VK_PRIOR;
        case 28: return VK_NEXT; case 29: return VK_NUMPAD0; case 30: return VK_NUMPAD1; case 31: return VK_NUMPAD2;
        case 32: return VK_NUMPAD3; case 33: return VK_NUMPAD4; case 34: return VK_NUMPAD5; case 35: return VK_NUMPAD6;
        case 36: return VK_NUMPAD7; case 37: return VK_NUMPAD8; case 38: return VK_NUMPAD9;
        default: return VK_F10;
    }
}

int GetIndexFromHotkey(int hotkey) {  //byte what was ur brain looking like when doing this bullshit you def felt like the :dingdong: emote ffs
    switch (hotkey) {
        case VK_F1: return 0; case VK_F2: return 1; case VK_F3: return 2; case VK_F4: return 3;
        case VK_F5: return 4; case VK_F6: return 5; case VK_F7: return 6; case VK_F8: return 7;
        case VK_F9: return 8; case VK_F10: return 9; case VK_F11: return 10; case VK_F12: return 11;
        case VK_LMENU: return 12; case VK_RMENU: return 13; case VK_LCONTROL: return 14; case VK_RCONTROL: return 15;
        case VK_LSHIFT: return 16; case VK_RSHIFT: return 17; case VK_TAB: return 18; case VK_CAPITAL: return 19;
        case VK_SPACE: return 20; case VK_RETURN: return 21; case VK_BACK: return 22; case VK_DELETE: return 23;
        case VK_INSERT: return 24; case VK_HOME: return 25; case VK_END: return 26; case VK_PRIOR: return 27;
        case VK_NEXT: return 28; case VK_NUMPAD0: return 29; case VK_NUMPAD1: return 30; case VK_NUMPAD2: return 31;
        case VK_NUMPAD3: return 32; case VK_NUMPAD4: return 33; case VK_NUMPAD5: return 34; case VK_NUMPAD6: return 35;
        case VK_NUMPAD7: return 36; case VK_NUMPAD8: return 37; case VK_NUMPAD9: return 38;
        default: return 9; // Default to F10 
    }
}

static std::vector<std::string> configs = Config::GetConfigList();
static std::string selected_config;
static char config_name[32] = "default";



void pGui::DrawMenu()
{
	if (!globals::open)
		return;

	static bool theme_applied = false;
	if (!theme_applied) { Themes::Dracula(); theme_applied = true; }

	ImGui::SetNextWindowSize(ImVec2(650, 450));
	ImGui::Begin("Lunacy Revived");
	{
		if (ImGui::Button("Player", ImVec2(153, 25))) { globals::tabs = 0; } ImGui::SameLine();
		if (ImGui::Button("Weapons", ImVec2(153, 25))) { globals::tabs = 1; } ImGui::SameLine();
		if (ImGui::Button("World", ImVec2(153, 25))) { globals::tabs = 2; } ImGui::SameLine();
		if (ImGui::Button("Configs", ImVec2(153, 25))) { globals::tabs = 3; }
#ifndef PUBLIC
		ImGui::ShowDemoWindow(); //dont include in user builds
#endif
		if (globals::tabs == 0)
		{

			static bool hotkey_initialized = false;
			if (!hotkey_initialized) {
				current_hotkey = GetIndexFromHotkey(globals::Ihooks::RecRoom::Movement::AirstuckHotkey);
				hotkey_initialized = true;
			}

			ImGui::SeparatorText("Camera");
			ImGui::Checkbox("FOV Changer", &globals::Ihooks::UnityEngine::Camera::FOVChanger);
			if (globals::Ihooks::UnityEngine::Camera::FOVChanger)
			{
				ImGui::SliderFloat("Custom FOV", &globals::Ihooks::UnityEngine::Camera::CustomFOV, 10.0f, 180.0f, "%.1f");
				ImGui::SliderFloat("Zoom FOV", &globals::Ihooks::UnityEngine::Camera::ZoomFOV, 10.0f, 50.0f, "%.1f");
				ImGui::Combo("Zoom Key", &current_key, keys, IM_ARRAYSIZE(keys)); // i fucking hate this
				switch (current_key) {
				case 0: globals::Ihooks::UnityEngine::Camera::ZoomKey = 'R'; break;
				case 1: globals::Ihooks::UnityEngine::Camera::ZoomKey = 'Z'; break;
				case 2: globals::Ihooks::UnityEngine::Camera::ZoomKey = VK_MBUTTON; break;
				case 3: globals::Ihooks::UnityEngine::Camera::ZoomKey = VK_SHIFT; break;
				case 4: globals::Ihooks::UnityEngine::Camera::ZoomKey = VK_CONTROL; break;
				case 5: globals::Ihooks::UnityEngine::Camera::ZoomKey = VK_GAMEPAD_DPAD_DOWN; break;
				}
				//ImGui::Checkbox("Toggle Zoom (Press Once)", &globals::Engine::Camera::ZoomToggleMode); //doesnt work retard code
				ImGui::Separator();

			}
			ImGui::SeparatorText("Player");
			ImGui::Checkbox("Dynamic Fly", &globals::Ihooks::RecRoom::Movement::dynamicFly);
			ImGui::Checkbox("Own All Keys", &globals::Ihooks::RecRoom::Player::OwnKeys);
			ImGui::Checkbox("Bypass Trial Items", &globals::Ihooks::RecRoom::Player::BypassTrialItems);

			ImGui::Checkbox("Custom Walk Speed", &globals::Ihooks::RecRoom::Player::WalkSpeedT);
			if (globals::Ihooks::RecRoom::Player::WalkSpeedT)
			{
				ImGui::SliderFloat("Speed", &globals::Ihooks::RecRoom::Player::walkspeed, 0.1f, 1000.0f, "%.1f");
			}

			// needs master idk it was working without master
			ImGui::Checkbox("God Mode All", &globals::Ihooks::RecRoom::Player::GodMode);

			ImGui::Checkbox("Dev Hook", &globals::Ihooks::RecRoom::Player::DevHook);
			ImGui::SeparatorText("Exploits");
			char airstuck_label[64];
			sprintf_s(airstuck_label, "Airstuck", hotkey_options[current_hotkey]); // we dont need an aistuck label :broken-heart:
			ImGui::Checkbox(airstuck_label, &globals::Ihooks::RecRoom::Movement::Airstuck);

			if (ImGui::Combo("Airstuck Hotkey", &current_hotkey, hotkey_options, IM_ARRAYSIZE(hotkey_options))) {
				globals::Ihooks::RecRoom::Movement::AirstuckHotkey = GetHotkeyFromIndex(current_hotkey);
			}
			ImGui::Checkbox("CFreeze Body", &globals::Ihooks::RecRoom::Player::CheckForBodyMovement);

		}

		if (globals::tabs == 1)
		{
			ImGui::SeparatorText("Weapons");
			ImGui::Checkbox("Anti Cooldown", &globals::Ihooks::RecRoom::Weapon::AntiCooldown);
			ImGui::Checkbox("Infinite Ammo", &globals::Ihooks::RecRoom::Weapon::InfiniteAmmo);
			ImGui::Checkbox("anti Drop Tool", &globals::Ihooks::RecRoom::Player::antiweapondrop);


			ImGui::SeparatorText("Modifiers");
			ImGui::Checkbox("Recoil Customizer", &globals::Ihooks::RecRoom::Weapon::AntiRecoil);
			if (globals::Ihooks::RecRoom::Weapon::AntiRecoil)
			{
				ImGui::SliderFloat("Recoil Amount", &globals::Ihooks::RecRoom::Weapon::CustomRecoilMultiplier, 0.0f, 100.0f, "%.1f");
			}
			ImGui::Checkbox("Spread Customizer", &globals::Ihooks::RecRoom::Weapon::NoSpreadCheck);
			if (globals::Ihooks::RecRoom::Weapon::NoSpreadCheck)
			{
				ImGui::SliderFloat("Spread Value", &globals::Ihooks::RecRoom::Weapon::NoSpreadValue, 0.0f, 100.0f, "%.1f");
			}
			ImGui::Checkbox("Bullet Toggle", &globals::Ihooks::RecRoom::Weapon::BulletToggle);
			if (globals::Ihooks::RecRoom::Weapon::BulletToggle)
			{
				ImGui::SliderInt("Bullet Amount", &globals::Ihooks::RecRoom::Weapon::BulletAmount, 1, 1000, "%d");
				if (ImGui::Button("RAM Server Crash (ENABLE BULLET HIDE)"))
				{
					globals::Ihooks::RecRoom::Weapon::BulletAmount = 100000;

				}
			}
			ImGui::Checkbox("Bullet Speed", &globals::Ihooks::RecRoom::Weapon::bulletspeecheck);
			if (globals::Ihooks::RecRoom::Weapon::bulletspeecheck)
			{
				ImGui::SliderFloat("Speed", &globals::Ihooks::RecRoom::Weapon::bulletspeed, 0.1, 10000.0f, "%.1f");
			}
			ImGui::Checkbox("Bullet Lifetime", &globals::Ihooks::RecRoom::Weapon::projectilelifecheck);
			if (globals::Ihooks::RecRoom::Weapon::projectilelifecheck)
			{
				ImGui::SliderFloat("Seconds", &globals::Ihooks::RecRoom::Weapon::projectileLifetime, 0.1, 1000.0f, "%.1f");
			}

		}

		if (globals::tabs == 2)
		{
			ImGui::SeparatorText("Quests");
			ImGui::Checkbox("Quest God-Mode", &globals::Ihooks::RecRoom::Player::QuestPlayerIsInvincible);
			ImGui::Checkbox("Point Multiplier", &globals::Ihooks::RecRoom::Quests::Points::QuestPointsModifier);
			if (globals::Ihooks::RecRoom::Quests::Points::QuestPointsModifier)
			{
				ImGui::SliderInt("Points", &globals::Ihooks::RecRoom::Quests::Points::QuestPointsInt, 1, 100000, "%d");
			}
			ImGui::Checkbox("Gold & Silver Multiplier", &globals::Ihooks::RecRoom::Quests::Points::QuestGoldModifier);
			if (globals::Ihooks::RecRoom::Quests::Points::QuestGoldModifier)
			{
				ImGui::SliderInt("Gold & Silver", &globals::Ihooks::RecRoom::Quests::Points::QuestGoldInt, 1, 100000, "%d");
			}



			ImGui::SeparatorText("Skippers");
			ImGui::Checkbox("Skip Golden Trophy", &globals::Ihooks::RecRoom::Quests::Skip::SkipGoldenTrophy);
			ImGui::Checkbox("Skip Crimson Cauldron", &globals::Ihooks::RecRoom::Quests::Skip::SkipCrims);
			ImGui::Checkbox("Skip Jumbotron", &globals::Ihooks::RecRoom::Quests::Skip::SkipJumbotron);
			ImGui::Checkbox("Skip Isle", &globals::Ihooks::RecRoom::Quests::Skip::SkipIsle);
			ImGui::Checkbox("Skip Crescendo", &globals::Ihooks::RecRoom::Quests::Skip::SkipCresendo);
			ImGui::Checkbox("Skip Boss", &globals::Ihooks::RecRoom::Quests::Skip::SkipBoss);
			ImGui::Checkbox("Custom Skipper", &globals::Ihooks::RecRoom::Quests::Skip::CustomSkip);
			if (globals::Ihooks::RecRoom::Quests::Skip::CustomSkip)
			{
				ImGui::SliderInt("Skip Level", &globals::Ihooks::RecRoom::Quests::Skip::CustomSkipper, 0, 99, "%d");
			}



			ImGui::SeparatorText("Antis");
			ImGui::Checkbox("Hide Bullets", &globals::Ihooks::RecRoom::Weapon::HideShots);
			ImGui::Checkbox("Hide level up", &globals::Ihooks::RecRoom::Anti::nopLevelUpCrash);
			ImGui::Checkbox("Hide Cheers", &globals::Ihooks::RecRoom::Anti::nopCheerCrash);
			ImGui::Checkbox("Hide Candles", &globals::Ihooks::RecRoom::Anti::nopCandles);
			ImGui::Checkbox("anti Despawn Player Crash", &globals::Ihooks::RecRoom::Anti::nopDespawnPlayer);
			ImGui::Checkbox("Nop OnEvent", &globals::Ihooks::RecRoom::Anti::nopOnEvent);
			ImGui::Checkbox("Nop All RPCS", &globals::Ihooks::RecRoom::Anti::nopEveryRPC);

			ImGui::SeparatorText("Vehicle");
			ImGui::Checkbox("Allow Car Boosting", &globals::Ihooks::RecRoom::Vehicle::GetAllowBoosting);
			ImGui::Checkbox("Custom Hitbox Size", &globals::Ihooks::RecRoom::Vehicle::HitBoxCheck);
			if (globals::Ihooks::RecRoom::Vehicle::HitBoxCheck)
			{
				ImGui::SliderFloat("Hitbox Size", &globals::Ihooks::RecRoom::Vehicle::HitboxSize, 0.1f, 100.0f, "%.1f");
			}
			ImGui::Checkbox("Custom Speed", &globals::Ihooks::RecRoom::Vehicle::SyncedVehicleSpeedCheck);
			if (globals::Ihooks::RecRoom::Vehicle::SyncedVehicleSpeedCheck)
			{
				ImGui::SliderFloat("Forward Speed", &globals::Ihooks::RecRoom::Vehicle::SyncedVehicleSpeedValue, 0.1f, 1000.0f, "%.1f");
			}
			ImGui::Checkbox("Custom Throttle", &globals::Ihooks::RecRoom::Vehicle::CurrentThrottleCheck);
			if (globals::Ihooks::RecRoom::Vehicle::CurrentThrottleCheck)
			{
				ImGui::SliderFloat("Throttle Value", &globals::Ihooks::RecRoom::Vehicle::CurrentThrottleValue, 0.1f, 100.0f, "%.1f");
			}
		}




		if (globals::tabs == 3)
		{

			ImGui::SeparatorText("Config System");
			ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(0, 0, 0, 0));
			ImGui::PushStyleColor(ImGuiCol_SeparatorHovered, ImVec4(0, 0, 0, 0));
			ImGui::PushStyleColor(ImGuiCol_SeparatorActive, ImVec4(0, 0, 0, 0));

			ImGui::Columns(2, "###config_cols", true);
			ImGui::SetColumnWidth(0, 180);

			ImGui::Text("Config Name");
			ImGui::SetNextItemWidth(-1);
			ImGui::InputText("##config_name", config_name, IM_ARRAYSIZE(config_name));
			ImGui::Dummy(ImVec2(0, 8));

			if (ImGui::Button("Save Config", ImVec2(-1, 30)))
			{
				Config::Save(std::string(config_name));
				configs = Config::GetConfigList();
				selected_config = std::string(config_name);
			}

			ImGui::Dummy(ImVec2(0, 6));
			if (ImGui::Button("Load Config", ImVec2(-1, 30)))
			{
				Config::Load(std::string(config_name));
			}

			ImGui::Dummy(ImVec2(0, 6));
			if (ImGui::Button("Delete Config", ImVec2(-1, 30)))
			{
				std::string name_to_delete(config_name);
				if (!name_to_delete.empty())
				{
					Config::Delete(name_to_delete);
					configs = Config::GetConfigList();
					if (selected_config == name_to_delete)
					{
						strcpy(config_name, "");
						selected_config = "";
					}
				}
			}

			ImGui::Dummy(ImVec2(0, 6));
			if (ImGui::Button("Refresh Configs", ImVec2(-1, 30)))
			{
				configs = Config::GetConfigList();
				selected_config = "";
			}

			ImGui::NextColumn();

			ImGui::Text("Saved Configs");
			ImGui::Separator();

			ImGui::BeginChild("###config_list", ImVec2(0, 0), true);

			for (size_t i = 0; i < configs.size(); ++i)
			{
				const std::string& name = configs[i];
				bool is_selected = (selected_config == name);

				if (ImGui::Selectable(name.c_str(), is_selected))
				{
					strcpy(config_name, name.c_str());
					selected_config = name;
				}
			}

			ImGui::EndChild();

			if (!selected_config.empty())
			{
				bool exists = std::find(configs.begin(), configs.end(), selected_config) != configs.end();
				if (!exists)
				{
					selected_config = "";
				}
			}

			ImGui::Columns(1);
			ImGui::PopStyleColor(3);

		}


	}
	ImGui::End();
}
