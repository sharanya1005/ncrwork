#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>

DWORD WINAPI thread_func(LPVOID lparam)
{
	for (int i = 0; i < 1000; i++)
	{
		printf("i=%d\n", i);
		Sleep(1000);
	}
	return 0;
}

int main() {
	DWORD thID1;
	HANDLE hthread1;


	hthread1 = CreateThread(NULL, //thread attributes
		0,	//stack size
		thread_func, //start address
		NULL, //lp parameter
		0, // creation flags
		&thID1);// lp Thread ID
	if (hthread1 == NULL)
	{
		printf("Unable to create thread\n");
		getchar();
		return FALSE;
	}
	Sleep(5000);
	ResumeThread(hthread1);
	CloseHandle(hthread1);

	printf("Waiting for user input before exiting\n");

	getchar();

	return 0;
}
