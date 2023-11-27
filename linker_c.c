#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#ifdef _MSC_VER
#    pragma comment(lib, "kernel32.lib")
#endif

void* __cdecl C_cdecl_function(void* ptr)
{
    static void* bla;
    bla = ptr;
    return &bla;
}

void* __stdcall C_stdcall_function(void* ptr)
{
    static void* bla;
    bla = ptr;
    return &bla;
}

void* __fastcall C_fastcall_function(void* ptr)
{
    static void* bla;
    bla = ptr;
    return &bla;
}

extern void* C_CXX_defined_function(void* ptr);

#if 0
int __cdecl main()
{
    return 0;
}
#else
#    ifdef _CONSOLE
int mainCRTStartup(void)
{
    void* x1 = C_fastcall_function((void*)mainCRTStartup);
    void* x2 = C_stdcall_function(x1);
    void* x3 = C_stdcall_function(x2);
    (void)C_CXX_defined_function(x3);
    ExitProcess(0);
}
#    else  // _CONSOLE
int WinMainCRTStartup(void)
{
    TerminateProcess(GetCurrentProcess(), 0);
}
#    endif // _CONSOLE
#endif
