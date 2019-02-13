#include<stdio.h>
struct student
{
	char ch;
	int roll_no;
};
union data
{
	int x;
	char ch;
};
int main()
{
	struct student s1;
	union data d1;
	printf("Size of structure is:%d\n ", sizeof(s1));
	printf("Size of union is:%d\n ", sizeof(d1));
	return 0;
}