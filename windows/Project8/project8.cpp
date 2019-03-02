#include<stdio.h>
#include<windows.h>
#include<tchar.h>
int main()
{
	HANDLE event = CreateEvent(NULL,
		FALSE,
		FALSE,
		TEXT("NamedEvent")  );
	CloseHandle(event);
	getchar();
	return 1;
}