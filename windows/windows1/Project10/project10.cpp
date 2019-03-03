#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
#define BUFFSIZE 100
void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si1;
	PROCESS_INFORMATION pi1;
	SECURITY_ATTRIBUTES sa;

	ZeroMemory(&si1, sizeof(si1));//fills a block of memory with zeros
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));

	
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	HANDLE hFile;
	TCHAR buffer[BUFFSIZE];
	hFile = CreateFile(argv[1], //file name
						GENERIC_READ, //access mode
						0, //shared mode
						NULL, //security attributes
						OPEN_EXISTING, //creation disposition
						FILE_ATTRIBUTE_NORMAL,//flags
						NULL);//template file
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("file doesnot exist Error(%d)\n"), GetLastError());
		getchar();
		return;
	}
	_tprintf(_T("File (%s)opened successfully\n"), argv[1]);
	if (argc != 3)
	{
		printf("Usage %S[cmdline]\n", argv[0]);
		getchar();
		return;
	}

	if (!CreateProcess(NULL, argv[2], NULL, NULL, TRUE, 0, NULL, NULL, &si1, &pi1))
	{
		printf("Create process Error %d", GetLastError());
		getchar();
		return;
	}

	printf("Current process id is %ld\n", GetCurrentProcessId());//retrieves the process identifier of the calling process
	printf("Current thread id is %ld\n", GetCurrentThreadId());//retrieves the thread identifier of the calling thread
	printf("process id of first process is %ld\n", GetProcessId(pi1.hProcess));//retrieves the process identifier of the specified process
	printf("thread id of first process is %ld\n", GetThreadId(pi1.hThread));//retrieves the thread identifier of the specified thread
	printf("Handle of first process is %ld \n", pi1.hProcess);//handle of first process


	getchar();
}