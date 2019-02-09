#include<stdio.h>
int main()
{
char *color[6] = {"red" , "green", "blue", "white", "black", "yellow" };
printf(" color = %d\n ",color);
printf(" (color+2) = %d\n ", (color+2) );
printf(" *color = %d\n ", *color);
printf(" *(color+2) = %d\n ", *(color+2) );
printf(" color[5] = %d\n ", color[5] );
printf(" *(color+5) = %d\n", *(color +5) );
}

