#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
void main()
{
	char a1 = 'A';
	CHAR a2 = 'P';
	wchar_t a3 = L'P';
	WCHAR a4 = L'L';
	TCHAR tc = TEXT('E');
	CHAR ArrayANSI[] = "sharanya";
	WCHAR ArrayWIDE[] = L"gandla";
	printf("char: %c\n CHAR: %c\n wchar_t: %C\n WCHAR: %C\n TCHAR:%c\n ArrayANSI: %s\n ArrayWIDE : %S\n", a1, a2, a3, a4, tc, ArrayANSI, ArrayWIDE);

	BOOL ret = IsTextUnicode(ArrayANSI, strlen(ArrayANSI), NULL);
	if (1 == ret)
		printf("ArrayANSI is a Unicode\n");
	else
		printf("ArrayANSI is not a Unicode\n");

	BOOL ret1 = IsTextUnicode(ArrayWIDE, wcslen(ArrayWIDE), NULL);
	if (1 == ret1)
		printf("ArrayWIDE is a Unicode\n");
	else
		printf("ArrayWIDE is not a Unicode\n");

	int len1 = MultiByteToWideChar(CP_UTF8, 0, ArrayANSI, -1, NULL, 0);
	if (len1 == 0)
		printf("Error has been occured i.e., %d\n", GetLastError());
	else
		printf("Length of ArrayANSI is: %d\n", len1);

	WCHAR *ANSITOWIDE = new WCHAR[len1];
	int len2 = MultiByteToWideChar(CP_UTF8, 0, ArrayANSI, -1, ANSITOWIDE, len1);
	if (len2 == 0)
		printf("Error has been occured i.e., %d\n", GetLastError());
	else
		printf("Length of ArrayANSI is: %S\n", ANSITOWIDE);

	int len3 = WideCharToMultiByte(CP_UTF8, 0, ArrayWIDE, -1, NULL, 0, NULL, NULL);
	if (len3 == 0)
		printf("Error has been occured i.e., %d\n", GetLastError());
	else
		printf("Length of ArrayWIDE is: %d\n", len3);

	CHAR *WIDETOANSI = new CHAR[len3];
	int len4 = WideCharToMultiByte(CP_UTF8, 0, ArrayWIDE, -1, WIDETOANSI, len3, NULL, NULL);
	if (len4 == 0)
		printf("Error has been occured i.e., %d\n", GetLastError());
	else
		printf("Length of ArrayANSI is: %s\n", WIDETOANSI);

	delete(ANSITOWIDE);
	delete(WIDETOANSI);

	getchar();

}
