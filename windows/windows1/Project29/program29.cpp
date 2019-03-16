#include<windows.h>
#include<stdio.h>
#define MAX_SEM_COUNT 2
#define ThreadCount 8
HANDLE ghSemaphore;
DWORD WINAPI ThreadProc(LPVOID);

int main(void) 
{
	HANDLE aThread[ThreadCount];
	DWORD ThreadID;
	int i;

	ghSemaphore = CreateSemaphore(NULL, //semaphore attributes
								MAX_SEM_COUNT, //initial count
								MAX_SEM_COUNT, //maximum count
								NULL);//unnamed semaphore

	if (ghSemaphore == NULL) 
	{
		printf("Create Semaphore error %d\n", GetLastError());
		return 1;
	}
	//create worker threads

	for (i = 0; i < ThreadCount; i++)
	{
		aThread[i] = CreateThread(NULL,//default security attributes
									0,//default stack size
								(LPTHREAD_START_ROUTINE)ThreadProc, 
								NULL, //no thread function arguments
								0, //default creation flags
								&ThreadID);//receive thread identifier

		if (aThread[i] == NULL) {
			printf("Create Semaphore error %d\n", GetLastError());
			return 1;
		}
	}
	//wait for all threads to terminate

	WaitForMultipleObjects(ThreadCount, aThread, TRUE, INFINITE);

	//close thread and semaphore handles

	for (i = 0; i <= ThreadCount; i++)

	CloseHandle(aThread[i]);
	CloseHandle(ghSemaphore);
	getchar();
	return 0;
}
DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	//lpParam not used in this example
	UNREFERENCED_PARAMETER(lpParam);
	DWORD dwWaitResult;
	//try to enter to semaphore gate

		dwWaitResult = WaitForSingleObject(ghSemaphore, //handle to semaphore
											0L);//zero-second time-out interval
		switch (dwWaitResult)
		{
			//the semaphore object was signaled

		case WAIT_OBJECT_0:

			printf("Thread %d: wait succeeded\n", GetCurrentThreadId());

	
			//simulate thread spending time on task

			Sleep(500);

			//release the semaphore when task is finished

			if (!ReleaseSemaphore(ghSemaphore,//HANDLE TO SEMAPHORE
									 1, //increase count by one
									NULL)) //not interested in previous count
			{
				printf("ReleaseSemaphore error:%d\n", GetLastError());
			}
			break;

			//the semaphore was non signaled, so a time-out occured

		case WAIT_TIMEOUT:
			printf("Thread %d: wait timed out\n", GetCurrentThreadId());
			break;
		}
	
	return TRUE;

}