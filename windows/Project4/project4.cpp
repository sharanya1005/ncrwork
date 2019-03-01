#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
#include<strsafe.h>

#define BUFFSIZE 100

int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hFile;
	TCHAR buffer[BUFFSIZE];
	if (argc != 2)//if no. of args are other than 2 then it throws a message
	{
		_tprintf(_T("Usage fileopen.exe<name of the file>\n"));
		getchar();
		return FALSE;
	}
	hFile = CreateFile(argv[1],//name of file
						GENERIC_READ,//desired access 
						0,//share mode
						NULL,//default security attributes
						OPEN_EXISTING,//creation disposition
						FILE_ATTRIBUTE_NORMAL,//flags and attributes
						NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File doesn't exist. Error(%d)\n"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("File (%s) opened successfully\n"), argv[1]);

	DWORD nbr;
	ZeroMemory(buffer, BUFFSIZE);
	BOOL ret = ReadFile(hFile, buffer, BUFFSIZE, &nbr, NULL);
	if (ret == 0)
	{
		_tprintf(_T("Can't read file. Error (%d)\n"), GetLastError());
		getchar();
		return FALSE;
	}
	CloseHandle(hFile);
	_tprintf(_T("Text from (%s) %hS\n"), argv[1], buffer);
	getchar();
	return TRUE;
}