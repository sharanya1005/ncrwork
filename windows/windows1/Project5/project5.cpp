#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<windows.h>
int _tmain(int argc, LPTSTR argv[])
{

	if (argc != 2)
	{
		_tprintf(_T("Usage fileopenread.exe <name of file>"));
		getchar();
		return FALSE;
	}
	HANDLE hFile;
	TCHAR buffer[] = TEXT("WELCOME!!!");
	hFile = CreateFile(argv[1], //file name
						GENERIC_WRITE,	//access mode
						0, //share mode
						NULL, //security attributes
						CREATE_ALWAYS, //creation disposition
						FILE_ATTRIBUTE_NORMAL, //flags 
						NULL);//template file
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File doesnot exist Error(%d)\n"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("File (%s)opened successfully\n"), argv[1]);
	DWORD nbw;
	BOOL ret1 = WriteFile(hFile, buffer, sizeof(buffer), &nbw, NULL);
	if (ret1 == 0)
	{
		printf("cannot open file");
	}
	CloseHandle(hFile);
	getchar();
}