#include "main.hpp"
#include <windows.h>
#include <Lmcons.h>
#include <fstream>
#include "utils/Console.hpp"
using namespace std;
void CorruptPEHeader(HMODULE base) {
    DWORD oldProtect;
    VirtualProtect(base, 0x200, PAGE_READWRITE, &oldProtect); //yes this works LMFAO
    ZeroMemory(base, 0x200);
    VirtualProtect(base, 0x200, oldProtect, &oldProtect);
}

class Entry {
public:
    static void initThread();
};

void Entry::initThread() {
    
#ifndef PUBLIC
    Console::Load();
#endif

    Main();
    return;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call != DLL_PROCESS_ATTACH) {
        return false;
    }
    CorruptPEHeader(hModule);
    DisableThreadLibraryCalls(hModule);
    CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Entry::initThread, hModule, 0, nullptr);

    return true;
}