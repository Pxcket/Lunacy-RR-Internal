#include "Camera.h"
#include <globals.hpp>
#include <HookingManager.h>
#include "../../offsets.h"
#include <stdio.h>

typedef void(__fastcall* tSetFOV)(void* _this, float fov, void* method);
tSetFOV SetFOV_O = nullptr;
void __fastcall SetFOV_H(void* instance, float fov, void* method)
{
    float newFov = globals::Ihooks::UnityEngine::Camera::FOVChanger
        ? globals::Ihooks::UnityEngine::Camera::CustomFOV
        : fov;

    SetFOV_O(instance, newFov, method);
}

void UnityEngineCamera::ApplyHooks()
{
    Ihooks::create((void**)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + offsets::UnityEngine::Camera::set_fieldOfView), &SetFOV_H, (void**)&SetFOV_O);
}