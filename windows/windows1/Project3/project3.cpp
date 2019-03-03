#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<tchar.h>
void DumpEnvStrings(PTSTR[]);
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	DumpEnvStrings(env);
	TCHAR envVar_String0[] = TEXT("%SystemRoot%");
	TCHAR envVar_String1[] = TEXT("%windir%");

	TCHAR buffer[MAX_PATH];
	DWORD exp;
	exp = ExpandEnvironmentStrings(envVar_String0, buffer, MAX_PATH);
	if (!exp)
	{
		printf("%d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("%ls\n", buffer);
	exp = ExpandEnvironmentStrings(envVar_String1, buffer, MAX_PATH);
	if (!exp)
	{
		printf("%d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("%ls\n", buffer);

	getchar();
	return 0;

}
void DumpEnvStrings(PTSTR pEnvBlock[])
{
	int current = 0;
	PTSTR *pelement = (PTSTR *)pEnvBlock;
	PTSTR pCurrent = NULL;
	while (pelement != NULL)
	{
		pCurrent = (PTSTR)(*pelement);
		if (pCurrent == NULL)
			pelement = NULL;
		else
		{
			_tprintf(TEXT(" [%u] %s\r\n"), current, pCurrent);
			current++;
			pelement++;
		}


	}

}