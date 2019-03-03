#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>

DWORD WINAPI thread_func(LPVOID lparam)
{
	printf("CHILD thread\n");
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
	CloseHandle(hthread1);

	printf("Waiting for user input before exiting the process\n");

	getchar();

	return 0;
}
