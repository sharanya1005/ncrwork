#include <iostream>
#include <cstdlib>
#include <queue>
#include <Windows.h>
#include <tchar.h>
using namespace std;
SRWLOCK g_srwlock;//slim reader-writer lock
CONDITION_VARIABLE g_cvReadyToConsume;//signaled by writers
CONDITION_VARIABLE g_cvReadyToProduce;//signaled by readers

volatile LONG isRunning = TRUE;//signals reader-writer threads to

//handles to all reader/writer threads
HANDLE g_hThreads[MAXIMUM_WAIT_OBJECTS];

//number of reader/writer threads
int g_numThreads = 0;

//size limit of shared queue
#define QSIZELIMIT 5

//object
struct object
{
	int ThreadNo;
	int element;
}obj;

//shared queue of integer variables
queue <object> gSharedQ;

DWORD WINAPI WriterThread(LPVOID lparam)
{
	int ThreadNo = PtrToUlong(lparam);
	
	for (int element = 1; isRunning; element++)
	{
		object obj = { ThreadNo, element};

		AcquireSRWLockExclusive(&g_srwlock);

		//check if Q is full
		if (gSharedQ.size() >= QSIZELIMIT && isRunning)
		{
			cout << "Writer Thread " << ThreadNo << " Q is full. Can't produce " << element << endl;

			//wait for element to be consumed by reader thread
			SleepConditionVariableSRW(&g_cvReadyToProduce, &g_srwlock, INFINITE, 0);
		}
		if (!isRunning)
		{
			cout << "Writer Thread " << ThreadNo << " bye " << endl;
			ReleaseSRWLockExclusive(&g_srwlock);

			WakeAllConditionVariable(&g_cvReadyToProduce);

			return 0;
		}
		else
		{
			//add to Q
			gSharedQ.push(obj);

			cout << "Writer Thread " << ThreadNo << " Produced " << element << endl;

			ReleaseSRWLockExclusive(&g_srwlock);

			WakeAllConditionVariable(&g_cvReadyToConsume);

			Sleep(1500);
		}
		cout << "Writer Thread " << ThreadNo << " bye " << endl;
	}
}
DWORD WINAPI ReaderThread(LPVOID lparam)
{
	int ThreadNo = PtrToUlong(lparam);
	for (int element = 1; isRunning; element++)
	{
		AcquireSRWLockExclusive(&g_srwlock);
		if (gSharedQ.empty() && isRunning)
		{
			cout << "Reader Thread " << ThreadNo << " Nothing to consume\n";
			SleepConditionVariableSRW(&g_cvReadyToConsume, &g_srwlock, INFINITE, CONDITION_VARIABLE_LOCKMODE_SHARED);
		}
		if (!isRunning)
		{
			cout << "ReaderThread  " << ThreadNo << " bye" << endl;
			ReleaseSRWLockShared(&g_srwlock);
			WakeAllConditionVariable(&g_cvReadyToConsume);
			return 0;
		}
		else
		{
			object obj = gSharedQ.front();
			cout << "Reader Thread consumed\n";
			gSharedQ.pop();
			ReleaseSRWLockShared(&g_srwlock);
			WakeAllConditionVariable(&g_cvReadyToProduce);
		}
		Sleep(2500);
	}
}
DWORD WINAPI HandlerRoutine(DWORD dwCtrlType)
{
	switch (dwCtrlType)
	{
	case CTRL_C_EVENT:
		cout << "[Ctrl]+C\n";
		InterlockedExchange(&isRunning, FALSE);
		WakeAllConditionVariable(&g_cvReadyToConsume);
		WakeAllConditionVariable(&g_cvReadyToProduce);
		return TRUE;
	default:
		return FALSE;
	}
}
int main()
{
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)HandlerRoutine, TRUE);

	//Init slim reader writer lock
	InitializeSRWLock(&g_srwlock);

	//Init producer and consumer condition variables
	InitializeConditionVariable(&g_cvReadyToConsume);
	InitializeConditionVariable(&g_cvReadyToProduce);

	//create writer threads
	DWORD dwThreadId;
	for (int i = 0; i < 4; i++)
	{
		g_hThreads[g_numThreads++] = CreateThread(NULL, 
													0, 
													WriterThread, 
													(PVOID)(INT_PTR)i,
													0, 
													&dwThreadId);
	}

	//create writer threads
	for (int i = 0; i < 2; i++)
	{
		g_hThreads[g_numThreads++] = CreateThread(NULL, 
													0, 
													ReaderThread, 
													(PVOID)(INT_PTR)i, 
													0, 
													&dwThreadId);
	}

	//wait for all threads to terminate and then clean up
	WaitForMultipleObjects(g_numThreads, g_hThreads, TRUE, INFINITE);
	while (g_numThreads--)
		CloseHandle(g_hThreads[g_numThreads]);
	return 1;
}