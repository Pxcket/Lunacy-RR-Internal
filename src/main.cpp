
#include "main.hpp"
#include "utils/CMD.hpp"
#include "dependencies/kiero/kiero.h"
#include "dependencies/Discord/discord_rpc.h"
#include "dependencies/imgui/backends/imgui_impl_win32.h"
#include "utils/globals.hpp"
#include "dependencies/imgui/backends/imgui_impl_dx11.h"
#include <DXGI.h>
#include <D3D11.h>
#include "resources/Fonts/PoppinsMedium.h"
#include "gui/menu.h"
#include "hooks/Inline.h"
#include "hooks/Classes/Referee/Bypass.h"
//#include <IL2CPP_Resolver.hpp>
typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static Present oPresent = nullptr;
static HWND window = nullptr;
static WNDPROC oWndProc = nullptr;
static ID3D11Device* pDevice = nullptr;
static ID3D11DeviceContext* pContext = nullptr;
static ID3D11RenderTargetView* mainRenderTargetView = nullptr;


void UpdateZoom() {
    if (!globals::Ihooks::UnityEngine::Camera::FOVChanger) return;

    if (globals::Ihooks::UnityEngine::Camera::ZoomToggleMode) {
        if (GetAsyncKeyState(globals::Ihooks::UnityEngine::Camera::ZoomKey) & 1)
        {

            globals::Ihooks::UnityEngine::Camera::IsZoomed = !globals::Ihooks::UnityEngine::Camera::IsZoomed;
            if (IsZoomed)
            {
                globals::Ihooks::UnityEngine::Camera::DefaultFOV = globals::Ihooks::UnityEngine::Camera::CustomFOV;
                globals::Ihooks::UnityEngine::Camera::CustomFOV = globals::Ihooks::UnityEngine::Camera::ZoomFOV; //Thats going to be the point where i kill myself
            }
            else {
                globals::Ihooks::UnityEngine::Camera::CustomFOV = globals::Ihooks::UnityEngine::Camera::DefaultFOV;
            }
        }
    }
    else {
        if (GetAsyncKeyState(globals::Ihooks::UnityEngine::Camera::ZoomKey) & 0x8000) {
            if (globals::Ihooks::UnityEngine::Camera::CustomFOV != globals::Ihooks::UnityEngine::Camera::ZoomFOV) {
                globals::Ihooks::UnityEngine::Camera::DefaultFOV = globals::Ihooks::UnityEngine::Camera::CustomFOV; //i lost 5k braincells its 1 am
                globals::Ihooks::UnityEngine::Camera::CustomFOV = globals::Ihooks::UnityEngine::Camera::ZoomFOV;
            }
        }
        else {
            if (globals::Ihooks::UnityEngine::Camera::CustomFOV == globals::Ihooks::UnityEngine::Camera::ZoomFOV) {
                globals::Ihooks::UnityEngine::Camera::CustomFOV = globals::Ihooks::UnityEngine::Camera::DefaultFOV;
            }
        }
    }
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_KEYUP && wParam == VK_DELETE)
    {
        globals::open ^= 1;
    }

    if (uMsg == WM_KEYUP && wParam == VK_INSERT)
    {
        globals::open ^= 1;
    }

    if (uMsg == WM_KEYUP && wParam == VK_F9)
    {
        globals::open ^= 1;
    }

    if (uMsg == WM_KEYUP && wParam == globals::Ihooks::RecRoom::Movement::AirstuckHotkey)
    {
        globals::Ihooks::RecRoom::Movement::Airstuck ^= 1;
    }

    if (globals::open)
    {
        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
        return true;
    }

    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

void InitImGui()
{
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
    ImGui_ImplWin32_Init(window);
    ImGui_ImplDX11_Init(pDevice, pContext);
    ImFontConfig font;
    font.FontDataOwnedByAtlas = false;
    io.Fonts->AddFontFromMemoryTTF((void*)PoppinsMedium, sizeof(PoppinsMedium), 17.5f, &font);
}

int Initialize();
static bool Init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
    if (!Init)
    {
        if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
        {
            pDevice->GetImmediateContext(&pContext);
            DXGI_SWAP_CHAIN_DESC sd;
            pSwapChain->GetDesc(&sd);
            window = sd.OutputWindow;
            ID3D11Texture2D* pBackBuffer;
            pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
            pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
            pBackBuffer->Release();
            oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
            InitImGui();
            Initialize();
            Init = true;
        }

        else
            return oPresent(pSwapChain, SyncInterval, Flags);
    }

    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    
    UpdateZoom();

    ImGui::GetIO().MouseDrawCursor = globals::open;

    pGui::DrawMenu();
    pGui::Watermark("Lunacy");
    ImGui::Render();
    pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    return oPresent(pSwapChain, SyncInterval, Flags);

}

LONG WINAPI ExceptionFixVectoredExceptionHandler(EXCEPTION_POINTERS* ExceptionInfo) // Exception Handler for Veh Hooking, But lets just use minhook for now :D
{ 
    return EXCEPTION_EXECUTE_HANDLER; 
}

void InitializeHooks()
{
    UnityEngineCamera::ApplyHooks();
    AntiAntiCheat::ApplyHooks();
    Weapon::ApplyHooks();
    RangedWeapon::ApplyHooks();
    Movement::ApplyHooks();
    LocalPlayer::ApplyHooks();
    QuestManager::ApplyHooks();
    Vehicle::ApplyHooks();
}

int Initialize()
{
    AddVectoredExceptionHandler(2, ExceptionFixVectoredExceptionHandler); //crash handler so easy that it works #NoBS


    InitializeHooks();

    return 0;
}

void initC()
{
    AddVectoredExceptionHandler(2, ExceptionFixVectoredExceptionHandler);
    //IL2CPP::Initialize();
    //IL2CPP::Callback::Initialize();// Calling This Gives Crashes But Fuck Who Knows why, Fix This Bullshit, maybe its the patterns in the callback, idfk
    kiero::bind(8, (void**)&oPresent, (void*)hkPresent);
    Referee::Bypass();
#ifndef PUBLIC
    CMD::success("Present Hooked.");
#endif 
}
void UpdatePresence()
{
    time_t startTime = time(nullptr);
    time_t elapsedTime = time(nullptr) - startTime;
    int hours = elapsedTime / 3600;
    int minutes = (elapsedTime % 3600) / 60;
    int seconds = elapsedTime % 60;
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.startTimestamp = startTime;
    discordPresence.startTimestamp = startTime;
    discordPresence.state = "https://discord.gg/dRMZEJrv4f";
    discordPresence.details = "Public Internal Rec Room Cheat";
    discordPresence.largeImageKey = "12";
    discordPresence.largeImageText = "Playing The User Build!";
    Discord_UpdatePresence(&discordPresence);
}

int Main()
{
#ifndef PUBLIC
    CMD::INIT_CMD();
    CMD::success("CMD initialized.");
#endif 
    static bool Done = false;

    while (!Done)
    {
        if (init(kiero::RenderType::D3D11) == kiero::Status::Success)
        {
            initC();
            Done = true;
        }
        if (globals::DiscordRPC)
        {
            DiscordEventHandlers Handle;
            memset(&Handle, 0, sizeof(Handle));
            Discord_Initialize("1403013740697358357", &Handle, 1, nullptr); //put the discord app id here
            UpdatePresence();
        }
    }

    return 0;
}
