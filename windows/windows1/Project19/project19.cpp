#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<tchar.h>
const int COUNT = 100;
int g_nsum = 0;
CRITICAL_SECTION g_cs;
DWORD WINAPI FirstThread(LPVOID lparam)
{
	EnterCriticalSection(&g_cs);
	g_nsum = 0;
	for (int i = 1; i <= COUNT; i++)
	{
		g_nsum += i;//sum of natural numbers
	}
	printf("g_nsum = %d\n", g_nsum);
	LeaveCriticalSection(&g_cs);
	return g_nsum;
}

DWORD WINAPI SecondThread(LPVOID lparam)
{
	EnterCriticalSection(&g_cs);
	g_nsum = 0;
	for (int i = 1; i <= COUNT; i++)
	{
		g_nsum += i;//sum of natural numbers
	}
	printf("g_nsum = %d\n", g_nsum);
	LeaveCriticalSection(&g_cs);
	return g_nsum;
}

int main()
{
	DWORD thID1, thID2;
	HANDLE hthread1, hthread2;
	HANDLE array_hand[2];
	//DWORD lpExitCode1, lpExitCode2;

	InitializeCriticalSectionAndSpinCount(&g_cs, 4000);
	InitializeCriticalSection(&g_cs);

	hthread1 = CreateThread(NULL, 0, FirstThread, NULL, 0, &thID1);
	if (hthread1 == NULL)
	{
		printf("Unable to create thread\n");
		getchar();
		return FALSE;
	}
	

	hthread2 = CreateThread(NULL, 0, SecondThread, NULL, 0, &thID1);
	if (hthread2 == NULL)
	{
		printf("Unable to create thread\n");
		getchar();
		return FALSE;
	}
	array_hand[0] = hthread1;
	array_hand[1] = hthread2;
	WaitForMultipleObjects(2,//count: number of objects we are creating
							array_hand, //handle
							TRUE, //retruns when all objects are signaled
							INFINITE);//function will return when all objects are signaled
	CloseHandle(hthread1);
	CloseHandle(hthread2);
	
	DeleteCriticalSection(&g_cs);
	printf("Waiting for user input before exiting process\n");
	getchar();
	return 0;
}