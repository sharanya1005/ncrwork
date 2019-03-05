#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
DWORD WINAPI thread_func(LPVOID  lparam)
{
	Sleep(2000);
	return 1;
}


int main()
{
	DWORD thid1;
	HANDLE hthread1;

	hthread1 = CreateThread(NULL, //thread attributes
							0, //stack size
							thread_func,//start address
							NULL, //parameter
							0,//creation flags
							&thid1);//thread ID
	if (hthread1 == NULL)
	{
		printf("Unable to create a thread\n");
		return 1;
	}

	//DWORD dw = WaitForSingleObject(hthread1, INFINITE);
	DWORD dw = WaitForSingleObject(hthread1, 5000);
	switch (dw)
	{
	case WAIT_OBJECT_0:
		printf("Thread is terminated. The state of the specified object is signaled\n");
		break;
	case WAIT_TIMEOUT:
		printf("Timeout expired and object's state is non signaled\n");
	case WAIT_FAILED:
		printf("Wait failed\n");
		break;
	}
	CloseHandle(hthread1);
	printf("waiting for user input before exiting the process\n");
	getchar();
	return 0;
}

