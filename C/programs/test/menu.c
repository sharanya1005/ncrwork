#include<stdio.h>
#include<string.h>
void count();
void removecomments();
void matchword();
void tabs();
int main()
{
	int a;
	printf("choose: \n 1.count \n 2.remove comments \n 3.matchword \n 4. tabs \n : ");
		scanf("%d", &a);
	switch (a)
	{
		case 1:
			count();
			break;
		case 2:
			removecomments();
			break;
		case 3:
			matchword();
			break;
		case 4:
			tabs();
			break;
		default: printf("Enter a valid number ");
			break;
	};
		
	return 0;
}