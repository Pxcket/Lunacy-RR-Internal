#include "Config.h"
#include <filesystem>
#include <Windows.h>
#include <string>
#include <vector>
#include <globals.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <shlobj.h>
#include <algorithm>

namespace fs = std::filesystem;

namespace Cam = globals::Ihooks::UnityEngine::Camera;
namespace RR = globals::Ihooks::RecRoom;
namespace Wpn = globals::Ihooks::RecRoom::Weapon;
namespace Anti = globals::Ihooks::RecRoom::Anti;
namespace Mov = globals::Ihooks::RecRoom::Movement;
namespace Ply = globals::Ihooks::RecRoom::Player;
namespace QP = globals::Ihooks::RecRoom::Quests::Points;
namespace QS = globals::Ihooks::RecRoom::Quests::Skip;

static std::string GetDocumentsPath()
{
    PWSTR wide_path = nullptr;
    if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_Documents, 0, nullptr, &wide_path)))
    {
        std::wstring wstr(wide_path);
        CoTaskMemFree(wide_path);
        return std::string(wstr.begin(), wstr.end());
    }
    return "";
}

std::string Config::GetConfigFolder()
{
    static std::string path;
    if (path.empty())
    {
        path = GetDocumentsPath();
        if (!path.empty() && path.back() != '\\') path += '\\';
        path += "Lunacy";
    }
    return path;
}

bool Config::InitializeFolder()
{
    std::string folder = GetConfigFolder();
    if (!fs::exists(folder))
    {
        std::error_code ec;
        if (!fs::create_directories(folder, ec))
            return false;
    }
    return true;
}

static std::string Obfuscate(std::string data)
{
    const char key = 'X';
    for (size_t i = 0; i < data.length(); ++i)
        data[i] ^= key;
    return data;
}
static std::string Deobfuscate(std::string data) { return Obfuscate(data); }

void Config::Save(const std::string& name)
{
    if (name.empty() || !InitializeFolder()) return;

    std::string path = GetConfigFolder() + "\\" + name + ".Lunacy";
    std::ostringstream oss;

    oss << "ui_open=" << globals::open << "\n";
    oss << "ui_discordrpc=" << globals::DiscordRPC << "\n";
    oss << "ui_tabs=" << globals::tabs << "\n"; //why do we save this? sob

    oss << "camera_fov_changer=" << Cam::FOVChanger << "\n";
    oss << "camera_custom_fov=" << Cam::CustomFOV << "\n";
    oss << "camera_zoom_fov=" << Cam::ZoomFOV << "\n";
    oss << "camera_zoom_key=" << (int)Cam::ZoomKey << "\n";
    oss << "camera_is_zoomed=" << Cam::IsZoomed << "\n";
    oss << "camera_default_fov=" << Cam::DefaultFOV << "\n";
    oss << "camera_zoom_toggle_mode=" << Cam::ZoomToggleMode << "\n";

    oss << "player_dev_hook=" << Ply::DevHook << "\n";
    oss << "player_quest_invincible=" << Ply::QuestPlayerIsInvincible << "\n";
    oss << "player_invention_spawn_bypass=" << Ply::InventionSpawnBypass << "\n";
    oss << "player_white_glove_creator=" << Ply::WhiteGloveCreator << "\n";
    oss << "player_tutorial_bypass=" << Ply::TutorialBypass << "\n";
    oss << "player_own_keys=" << Ply::OwnKeys << "\n";
    oss << "player_bypass_hostareas=" << Ply::BypassHostOnlyAreas << "\n";
    oss << "player_god_mode=" << Ply::GodMode << "\n";

    oss << "weapon_anti_cooldown=" << Wpn::AntiCooldown << "\n";
    oss << "weapon_infinite_ammo=" << Wpn::InfiniteAmmo << "\n";
    oss << "weapon_one_hit_kill=" << Wpn::OneHitKill << "\n";
    oss << "weapon_aim_assist=" << Wpn::AimAssist << "\n";
    oss << "weapon_auto_fire=" << Wpn::AutoFireEnabled << "\n";
    oss << "weapon_anti_recoil=" << Wpn::AntiRecoil << "\n";
    oss << "weapon_custom_recoil_mult=" << Wpn::CustomRecoilMultiplier << "\n";
    oss << "weapon_max_fire_rate=" << Wpn::MaximFiringRate << "\n";
    oss << "weapon_custom_fire_rate=" << Wpn::CustomFireRate << "\n";
    oss << "weapon_bullet_toggle=" << Wpn::BulletToggle << "\n";
    oss << "weapon_bullet_amount=" << Wpn::BulletAmount << "\n";
    oss << "weapon_no_spread_check=" << Wpn::NoSpreadCheck << "\n";
    oss << "weapon_no_spread_value=" << Wpn::NoSpreadValue << "\n";
    oss << "weapon_bulletspeed_check=" << Wpn::bulletspeecheck << "\n";
    oss << "weapon_bulletspeed=" << Wpn::bulletspeed << "\n";
    oss << "weapon_projectile_lifetime=" << Wpn::projectileLifetime << "\n";
    oss << "weapon_projectile_life_check=" << Wpn::projectilelifecheck << "\n";
    oss << "weapon_hide_shots=" << Wpn::HideShots << "\n";

    oss << "movement_dynamicfly=" << Mov::dynamicFly << "\n";
    oss << "movement_airstuck=" << Mov::Airstuck << "\n";
    oss << "movement_airstuck_hotkey=" << Mov::AirstuckHotkey << "\n";

    oss << "anti_nop_every_rpc=" << Anti::nopEveryRPC << "\n";
    oss << "anti_nop_on_event=" << Anti::nopOnEvent << "\n";
    oss << "anti_nop_candles=" << Anti::nopCandles << "\n";
    oss << "anti_nop_cheer_crash=" << Anti::nopCheerCrash << "\n";
    oss << "anti_nop_despawn_player=" << Anti::nopDespawnPlayer << "\n";
    oss << "anti_nop_levelup_crash=" << Anti::nopLevelUpCrash << "\n";

    oss << "quest_points_modifier=" << QP::QuestPointsModifier << "\n";
    oss << "quest_points_value=" << QP::QuestPointsInt << "\n";
    oss << "quest_gold_modifier=" << QP::QuestGoldModifier << "\n";
    oss << "quest_gold_value=" << QP::QuestGoldInt << "\n";

    oss << "quest_skip_golden_trophy=" << QS::SkipGoldenTrophy << "\n";
    oss << "quest_skip_crims=" << QS::SkipCrims << "\n";
    oss << "quest_skip_jumbotron=" << QS::SkipJumbotron << "\n";
    oss << "quest_skip_isle=" << QS::SkipIsle << "\n";
    oss << "quest_skip_crescendo=" << QS::SkipCresendo << "\n";
    oss << "quest_skip_boss=" << QS::SkipBoss << "\n";
    oss << "quest_skip_custom=" << QS::CustomSkip << "\n";
    oss << "quest_skip_custom_value=" << QS::CustomSkipper << "\n";

    const std::string data = oss.str();
    const std::string encrypted = Obfuscate(data);
    std::ofstream file(path, std::ios::binary);
    if (file.is_open())
    {
        file.write(encrypted.c_str(), (std::streamsize)encrypted.size());
        file.close();
    }
}

void Config::Load(const std::string& name)
{
    if (name.empty()) return;
    std::string path = GetConfigFolder() + "\\" + name + ".Lunacy";
    if (!fs::exists(path)) return;

    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) return;

    std::ostringstream oss;
    oss << file.rdbuf();
    std::string encrypted = oss.str();
    file.close();

    if (encrypted.empty()) return;

    std::string data = Deobfuscate(encrypted);
    std::istringstream iss(data);
    std::string line;

#define SET_BOOL(k, var)  if (key == k) { var = (value == "1"); continue; }
#define SET_INT(k, var)   if (key == k) { var = std::stoi(value); continue; } //macros because i cant doing allat :sunglasses:
#define SET_FLOAT(k, var) if (key == k) { var = std::stof(value); continue; }
#define SET_CHAR(k, var)  if (key == k) { var = (char)std::stoi(value); continue; }

    while (std::getline(iss, line))
    {
        auto eq = line.find('=');
        if (eq == std::string::npos) continue;

        std::string key = line.substr(0, eq);
        std::string value = line.substr(eq + 1);

        SET_BOOL("ui_open", globals::open);
        SET_BOOL("ui_discordrpc", globals::DiscordRPC);
        SET_INT("ui_tabs", globals::tabs);

        SET_BOOL("camera_fov_changer", Cam::FOVChanger);
        SET_FLOAT("camera_custom_fov", Cam::CustomFOV);
        SET_FLOAT("camera_zoom_fov", Cam::ZoomFOV);
        SET_CHAR("camera_zoom_key", Cam::ZoomKey);
        SET_BOOL("camera_is_zoomed", Cam::IsZoomed);
        SET_FLOAT("camera_default_fov", Cam::DefaultFOV);
        SET_BOOL("camera_zoom_toggle_mode", Cam::ZoomToggleMode);

        SET_BOOL("player_dev_hook", Ply::DevHook);
        SET_BOOL("player_quest_invincible", Ply::QuestPlayerIsInvincible);
        SET_BOOL("player_invention_spawn_bypass", Ply::InventionSpawnBypass);
        SET_BOOL("player_white_glove_creator", Ply::WhiteGloveCreator);
        SET_BOOL("player_tutorial_bypass", Ply::TutorialBypass);
        SET_BOOL("player_own_keys", Ply::OwnKeys);
        SET_BOOL("player_bypass_hostareas", Ply::BypassHostOnlyAreas);
        SET_BOOL("player_god_mode", Ply::GodMode);

        SET_BOOL("weapon_anti_cooldown", Wpn::AntiCooldown);
        SET_BOOL("weapon_infinite_ammo", Wpn::InfiniteAmmo);
        SET_BOOL("weapon_one_hit_kill", Wpn::OneHitKill);
        SET_BOOL("weapon_aim_assist", Wpn::AimAssist);
        SET_BOOL("weapon_auto_fire", Wpn::AutoFireEnabled);
        SET_BOOL("weapon_anti_recoil", Wpn::AntiRecoil);
        SET_FLOAT("weapon_custom_recoil_mult", Wpn::CustomRecoilMultiplier);
        SET_FLOAT("weapon_max_fire_rate", Wpn::MaximFiringRate);
        SET_BOOL("weapon_custom_fire_rate", Wpn::CustomFireRate);
        SET_BOOL("weapon_bullet_toggle", Wpn::BulletToggle);
        SET_INT("weapon_bullet_amount", Wpn::BulletAmount);
        SET_BOOL("weapon_no_spread_check", Wpn::NoSpreadCheck);
        SET_FLOAT("weapon_no_spread_value", Wpn::NoSpreadValue);
        SET_BOOL("weapon_bulletspeed_check", Wpn::bulletspeecheck);
        SET_FLOAT("weapon_bulletspeed", Wpn::bulletspeed);
        SET_FLOAT("weapon_projectile_lifetime", Wpn::projectileLifetime);
        SET_BOOL("weapon_projectile_life_check", Wpn::projectilelifecheck);
        SET_BOOL("weapon_hide_shots", Wpn::HideShots);

        SET_BOOL("movement_dynamicfly", Mov::dynamicFly);
        SET_BOOL("movement_airstuck", Mov::Airstuck);
        SET_INT("movement_airstuck_hotkey", Mov::AirstuckHotkey);

        SET_BOOL("anti_nop_every_rpc", Anti::nopEveryRPC);
        SET_BOOL("anti_nop_on_event", Anti::nopOnEvent);
        SET_BOOL("anti_nop_candles", Anti::nopCandles);
        SET_BOOL("anti_nop_cheer_crash", Anti::nopCheerCrash);
        SET_BOOL("anti_nop_despawn_player", Anti::nopDespawnPlayer);
        SET_BOOL("anti_nop_levelup_crash", Anti::nopLevelUpCrash);

        SET_BOOL("quest_points_modifier", QP::QuestPointsModifier);
        SET_INT("quest_points_value", QP::QuestPointsInt);
        SET_BOOL("quest_gold_modifier", QP::QuestGoldModifier);
        SET_INT("quest_gold_value", QP::QuestGoldInt);

        SET_BOOL("quest_skip_golden_trophy", QS::SkipGoldenTrophy);
        SET_BOOL("quest_skip_crims", QS::SkipCrims);
        SET_BOOL("quest_skip_jumbotron", QS::SkipJumbotron);
        SET_BOOL("quest_skip_isle", QS::SkipIsle);
        SET_BOOL("quest_skip_crescendo", QS::SkipCresendo);
        SET_BOOL("quest_skip_boss", QS::SkipBoss);
        SET_BOOL("quest_skip_custom", QS::CustomSkip);
        SET_INT("quest_skip_custom_value", QS::CustomSkipper);
    }

#undef SET_BOOL
#undef SET_INT
#undef SET_FLOAT
#undef SET_CHAR
}

void Config::Delete(const std::string& name)
{
    std::string path = GetConfigFolder() + "\\" + name + ".Lunacy";
    if (fs::exists(path)) fs::remove(path);
}

std::vector<std::string> Config::GetConfigList()
{
    std::vector<std::string> list;
    std::string folder = GetConfigFolder();

    if (!fs::exists(folder)) return list;

    for (const auto& entry : fs::directory_iterator(folder))
    {
        if (entry.is_regular_file())
        {
            std::string filename = entry.path().filename().string();
            if (filename.length() > 7 &&
                _stricmp(filename.substr(filename.length() - 7).c_str(), ".Lunacy") == 0)
                list.push_back(filename.substr(0, filename.length() - 7));
        }
    }
    std::sort(list.begin(), list.end());
    return list;
}
