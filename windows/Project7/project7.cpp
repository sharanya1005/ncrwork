#include<windows.h>
#include<stdio.h>
#include<tchar.h>

void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO sin1, sin2;
	PROCESS_INFORMATION pin1,pin2;
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
	printf("Handle of process: %ld\n", pin1.hProcess);
	printf("ProcessID of process: %ld\n", pin1.dwProcessId);
	printf("Primary Thread ID of process %ld\n", pin1.dwThreadId);
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
	printf("Handle of process: %ld\n", pin2.hProcess);
	printf("ProcessID of process: %ld\n", pin2.dwProcessId);
	printf("Primary Thread ID of process %ld\n", pin2.dwThreadId);
	CloseHandle(pin2.hThread);
	CloseHandle(pin2.hProcess);
	getchar();

}