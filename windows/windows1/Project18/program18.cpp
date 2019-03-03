#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>

long g_a = 0;
DWORD WINAPI ThreadFunc_1(LPVOID lparam)
{
	InterlockedExchangeAdd(&g_a, 1);
	return 0;
}
DWORD WINAPI ThreadFunc_2(LPVOID lparam)
{
	InterlockedExchangeAdd(&g_a, 1);
	return 0;
}

int main() {
	DWORD thID1, thID2;
	HANDLE hThread1, hThread2;
	HANDLE array_hand[2];

	while (1)
	{
		g_a = 0;

		hThread1 = CreateThread(NULL,
			0,
			ThreadFunc_1,
			NULL,
			0,
			&thID1);
		if (hThread1 == NULL)
		{
			printf("Unable to create a thread due to %d \n", GetLastError());
			getchar();
			return FALSE;
		}

		hThread2 = CreateThread(NULL,
			0,
			ThreadFunc_2,
			NULL,
			0,
			&thID2);
		if (hThread2 == NULL)
		{
			printf("Unable to create a thread due to %d\n", GetLastError());
			getchar();
			return FALSE;
		}
		array_hand[0] = hThread1;
		array_hand[1] = hThread2;

		WaitForMultipleObjects(2, array_hand, TRUE, INFINITE);

		printf("g_a value is %d\n", g_a);
		if (g_a == 1)
			break;
	}
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	printf("waiting for user input before exiting");
	getchar();
	return 0;
}