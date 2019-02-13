#include<stdio.h>
struct time
{
	int hours;
	int minutes;
	int seconds;
};
int main()
{
	struct time t1;
	printf("Enter hours: ");
	scanf("%d", &t1.hours);
	printf("Enter minutes: ");
	scanf("%d", &t1.minutes);
	printf("Enter seconds: ");
		scanf("%d", &t1.seconds);
		printf("Hours: %d\t", t1.hours);
		printf("Minutes: %d\t", t1.minutes);
		printf("Seconds:%d ", t1.seconds);
		return 0;
}