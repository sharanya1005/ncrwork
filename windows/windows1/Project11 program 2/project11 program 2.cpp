#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO sin1;
	PROCESS_INFORMATION pin1;
	ZeroMemory(&sin1, sizeof(sin1));
	sin1.cb = sizeof(sin1);
	ZeroMemory(&pin1, sizeof(pin1));

	if (!CreateProcess(NULL,
		_T("notepad.exe"),
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&sin1,
		&pin1))
	{
		printf("Create process Error %d", GetLastError());
		getchar();
		return;
	}
}