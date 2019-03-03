#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
long g_x;
DWORD exit_code;
DWORD WINAPI secondary_thread(LPVOID lparam)
{
	g_x++;
	printf("Secondary thread %ld\n", g_x);

	return 0;
}
int main()
{
	DWORD thid1;
	HANDLE hthread1;
	g_x = 0;
	printf("In primary thread g_x value is %ld\n", g_x);
	hthread1 = CreateThread(NULL, 0, secondary_thread, NULL, CREATE_SUSPENDED, &thid1);
	if (hthread1 == NULL)
	{
		printf("Cannot create a thread due to error  %d", GetLastError());
		getchar();
		return FALSE;
	}
	WaitForSingleObject(hthread1, 1000);

	TerminateThread(hthread1, exit_code);

	printf(" exit code is %ld\n", GetExitCodeThread(hthread1, &exit_code));

	CloseHandle(hthread1);
	printf("In secondary thread g_x value is %ld\n", g_x);
	printf("Waiting for user input before exiting\n");
	getchar();
	return 0;
}