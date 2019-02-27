#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])//commandline argument
{
	LPWSTR *ArgList;
	int i;
	int Args = argc;//as th no. of args are given dynamically, at compile time it throws an error so taking a copy of it
	ArgList = CommandLineToArgvW(GetCommandLineW(), &Args);
	if (ArgList == NULL)
	{
		printf("No Command Line Arguments passed\n");
	}
	else
	{
		for (i = 0; i < Args; i++)
			printf("%d: %hS\n", i, argv[i]);
	}
	getchar();

}