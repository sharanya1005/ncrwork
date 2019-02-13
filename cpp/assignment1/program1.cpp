#include<iostream>
using namespace std;
class time
{
int hours;
int minutes;
int seconds;
public:
time()
{
hours = 0;
minutes = 0;
seconds = 0;
}
time(int x,int y,int z)
{
hours = x;
minutes = y;
seconds = z;
}
void time_format()
{
cout<<hours<<":"<<minutes<<":"<<seconds<<endl;
}

void add_time(time &t1, time &t2)
{
seconds = t1.seconds + t2.seconds;
minutes = t1.minutes + t2.minutes;
hours = t1.hours + t2.hours;
if(seconds >=60)
{
minutes++;
seconds = seconds - 60;
}

if(minutes>=60)
{
hours++;
minutes = minutes - 60;
}
if(hours>23)
hours = 0;
}
};
int main()
{
time t1(10, 5,8) , t2(1,55,52) ,t3;
t3.add_time(t1,t2);
t3.time_format();
return 0;
}
