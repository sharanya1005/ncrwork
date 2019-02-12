#include<stdio.h>
#define book(name, author) #name " is written by " #author
#define print(s) printf("token"#s"=%d", token##s)
int main()
{
#ifdef book
printf("%s\n", book(ANSI C, Swamy) );
#endif

#ifdef print(s)
int token9 = 100;
print(9);
#else
printf("Wrong);
#endif
}