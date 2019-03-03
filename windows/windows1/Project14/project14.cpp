//#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
long g_x;
DWORD exit_code;
DWORD WINAPI secondary_thread(LPVOID lparam)
{
	g_x++;

	ExitThread(exit_code);
}
int main()
{
	DWORD thid1;
	HANDLE hthread1;
	g_x = 0;
	printf("In primary thread g_x value is %ld\n", g_x);

	hthread1 = CreateThread(NULL, //thread attributes
							0, //stack size
							secondary_thread,//start address
							NULL, //parameter
							CREATE_SUSPENDED,//creation flags
							&thid1);//thread ID
	if (hthread1 == NULL)
	{
		printf("Unable to thread to create %d", GetLastError());
		getchar();
		return FALSE;
	}
	WaitForSingleObject(hthread1, 5000);

	GetExitCodeThread(hthread1, LPDWORD(exit_code));

	CloseHandle(hthread1);

	printf(" In secondary thread g_x value is %ld\n", g_x);

	printf("Waiting for user input before exiting\n");
	getchar();
	return 0;
}