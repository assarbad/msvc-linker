; Is this x86-64 or x86-32?
IFDEF RAX
PVOID TYPEDEF QWORD
ELSE
.386
.model flat, stdcall
PVOID TYPEDEF DWORD
ENDIF

extern C_cdecl_function : PROC

IFDEF RAX ; 64-bit

extern C_stdcall_function : PROC
extern C_fastcall_function : PROC

ELSE ; 32-bit

extern C_stdcall_function@4 : PROC

OPTION LANGUAGE: SYSCALL ; prevent the prepended underscore
extern @C_fastcall_function@4 : PROC

ENDIF

.DATA

IFDEF RAX ; 64-bit

__imp_C_cdecl_function PVOID C_cdecl_function
__imp_C_stdcall_function PVOID C_stdcall_function
__imp_C_fastcall_function PVOID C_fastcall_function
externdef __imp_C_cdecl_function : PVOID
externdef __imp_C_stdcall_function : PVOID
externdef __imp_C_fastcall_function : PVOID

ELSE ; 32-bit

__imp__C_cdecl_function PVOID C_cdecl_function
__imp__C_stdcall_function@4 PVOID C_stdcall_function@4
__imp__@C_fastcall_function@4 PVOID @C_fastcall_function@4
externdef __imp__C_cdecl_function : PVOID
externdef stdcall __imp__C_stdcall_function@4 : PVOID
externdef __imp__@C_fastcall_function@4 : PVOID

ENDIF

; .CREF / .NOCREF
; INCLUDELIB libraryname

end ; DATA
