void* __cdecl CXX_cdecl_function(void* ptr)
{
    static void* bla;
    bla = ptr;
    return &bla;
}

void* __stdcall CXX_stdcall_function(void* ptr)
{
    static void* bla;
    bla = ptr;
    return &bla;
}

extern "C" void* C_CXX_defined_function(void* ptr)
{
    static void* bla;
    bla = CXX_cdecl_function(CXX_stdcall_function(ptr));
    return &bla;
}
