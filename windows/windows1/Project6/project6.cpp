#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si;
	HANDLE hproc;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (argc != 2)
	{
		printf("Usage %S[cmdline]\n", argv[0]);
		getchar();
		return;
	}

	if (!CreateProcess(NULL,//application name
		argv[1], //command line
		NULL, //process attributes
		NULL,//thread attributes
		FALSE,//inherit handles
		0,//flags
		NULL, //environment
		NULL,//current directory
		&si, //start up info
		&pi))//process information
	{
		printf("Create process Error %d", GetLastError());
		getchar();
		return;
	}

	printf("Handle of first process is %ld \n", pi.hProcess);
	printf("Process id of first process is %ld \n", pi.dwProcessId);
	printf("primary thread id of first procezs is %ld\n", pi.dwThreadId);
	CloseHandle(pi.hProcess);
	getchar();
}
