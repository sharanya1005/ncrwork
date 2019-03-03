#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
#define BUFFSIZE 100
void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO sin1;
	PROCESS_INFORMATION pin1;
	SECURITY_ATTRIBUTES sa;

	ZeroMemory(&sin1, sizeof(sin1));
	sin1.cb = sizeof(sin1);
	ZeroMemory(&pin1, sizeof(pin1));
	
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	HANDLE hFile;
	TCHAR buffer[BUFFSIZE];
	if (argc != 2)
	{
		printf("Usage %hS[cmdline]\n", argv[0]);
		getchar();
		return;
	}
	hFile = CreateFile(argv[1],//file name
						GENERIC_READ,	//access mode
						0, //shared mode
						NULL,//security attributes
						OPEN_EXISTING,//creation disposition
						FILE_ATTRIBUTE_NORMAL,//creation flags
						NULL);//template file
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("file doesnot exist Error(%d)\n"), GetLastError());
		getchar();
		return;
	}
	_tprintf(_T("File (%s)opened successfully\n"), argv[1]);

	if (!CreateProcess(("project11 program 2.exe"), //application name
						NULL, //command line
						NULL,//process attributes
						NULL,//thread attributes
						TRUE, //inherit handles
						0,//creation flags
						NULL,//environment
						NULL,//current directory
						&sin1,//startup info
						&pin1))//process information
	{
		printf("Create process Error %d", GetLastError());
		getchar();
		return;
	}

	printf("Current process id is %ld\n", GetCurrentProcessId());
	printf("Current thread id is %ld\n", GetCurrentThreadId());
	printf("process id of first process is %ld\n", GetProcessId(pin1.hProcess));
	printf("thread id of first process is %ld\n", GetThreadId(pin1.hThread));

	getchar();
}