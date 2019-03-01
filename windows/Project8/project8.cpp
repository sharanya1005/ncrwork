#include<windows.h>
#include<stdio.h>
#include<tchar.h>

void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO sin1, sin2;
	PROCESS_INFORMATION pin1, pin2;
	SECURITY_ATTRIBUTES satt;
	HANDLE hproc;

	ZeroMemory(&sin1, sizeof(sin1));
	ZeroMemory(&sin2, sizeof(sin2));
	sin1.cb = sizeof(sin1);
	sin2.cb = sizeof(sin2);
	ZeroMemory(&pin1, sizeof(pin1));
	ZeroMemory(&pin2, sizeof(pin2));
	satt.nLength = sizeof(satt);
	satt.lpSecurityDescriptor = NULL;
	satt.bInheritHandle = TRUE;
	if (argc != 3)
	{
		printf("Usage\n");
		getchar();
		return;
	}
	if (!CreateProcess(NULL,//application name
		argv[1],//command line
		NULL,//process security attributes
		NULL,//thread security
		FALSE,//not inheritable
		0,//creation flage
		NULL,//environment
		NULL,//current directory
		&sin1,//startup info
		&pin1))//old process info
	{
		printf("Create process Error(%d)\n", GetLastError());
		getchar();
		return;
	}
	printf("Handle of process 1: %ld\n", pin1.hProcess);
	printf("ProcessID of process 1: %ld\n", pin1.dwProcessId);
	printf("Primary Thread ID of process 1:  %ld\n", pin1.dwThreadId);
	CloseHandle(pin1.hThread);
	CloseHandle(pin1.hProcess);

	if (!CreateProcess(NULL,//application name
		argv[2],//command line
		NULL,//process security attributes
		NULL,//thread security
		FALSE,//not inheritable
		0,//creation flage
		NULL,//environment
		NULL,//current directory
		&sin2,//startup info
		&pin2))//old process info
	{
		printf("Create process Error(%d)\n", GetLastError());
		getchar();
		return;
	}
	printf("Handle of process 2: %ld\n", pin2.hProcess);
	printf("ProcessID of process 2: %ld\n", pin2.dwProcessId);
	printf("Primary Thread ID of process 2 : %ld\n", pin2.dwThreadId);


	printf("Current processID of process 1: %ld\n", GetCurrentProcessId());//main function ID
	printf("Current ThreadID of process 1: %ld\n", GetCurrentThreadId());//primary thread of main function ID
	printf("Current ProcessID of process : %ld\n", GetProcessId);//notepad process ID
	printf("Current ThreadID of process : %ld\n", GetThreadId);//notepad thread ID
	printf("Current ProcessIDOfThread of process : %ld\n", GetProcessIdOfThread);//process1 thread process ID
	//printf("Current ProcessID of process 2: %ld\n", GetProcessId(pin2.hProcess) );//notepad process ID
	//printf("Current ThreadID of process 2: %ld\n", GetThreadId(pin2.hThread));//notepad thread ID
	//printf("Current ProcessIDOfThread of process 2: %ld\n", GetProcessIdOfThread);//process1 thread process ID
	CloseHandle(pin2.hThread);
	CloseHandle(pin2.hProcess);
	getchar();

}