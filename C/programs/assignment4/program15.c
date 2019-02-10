#include<stdio.h>
int strlen(char []);
int strcpy(char [], char []);
int strcat(char [], char []);
int strcmp(char [] , char []);
int strrev(char []);
int main()
{
char a[15],s1[15],s2[15],s3[20],s4[20],s5[20],s6[20],s7[24];
printf("Enter a string to find it's length: ");
scanf("%s", a);
strlen(a);
printf("Enter string s1: \n");
scanf("%s",s1);
printf("Enter string s2: \n");
scanf("%s",s2);
strcpy(s2,s1);
printf("Enter string s3: \n");
scanf("%s",s3);
printf("Enter string s4: \n");
scanf("%s",s4);
strcat(s3,s4);
printf("Enter string s5: \n");
scanf("%s",s5);
printf("Enter string s6: \n");
scanf("%s",s6);
int k=strcmp(s5, s6);
	if (k == 0)
		printf("strings are equal\n");
	else
		printf("strings are not equal\n");
printf("Enter string s7: \n");
scanf("%s",s7);
strrev(s7);
return 0;
}

int strlen(char a[])
{
int count=0,i;
for(i=0;a[i]!='\0' ;i++)
count++;
printf("Length of the entered string is: %d\n",count);
return count;
}

int strcpy(char s2[], char s1[])
{
int i=0;
while( (s2[i] = s1[i])!='\0' )
i++;
printf("copied string is: %s\n",s2);
return 0;
}

int strcat(char s3[], char s4[])
{
int i=0;
while(s3[i]!='\0')
i++;
int j=0;
while( (s3[i]=s4[j])!='\0' )
{
i++;
j++;
}
printf("concatenated string is: %s\n",s3);
return 0;
}

int strcmp(char s5[], char s6[])
{
int i=0,result=0;
while( s5[i] == s6[i] )
{
if(s5[i] == '\0')
return 0;
++i;
}
printf("result: %d",(s5[i] - s6[i]));
return (s5[i] - s6[i]);
}

int strrev(char s7[])
{
char temp;
for(int i=0 , j=strlen(s7)-1; i<j; i++,j-- )
{
temp = s7[i];
s7[i] = s7[j];
s7[j] = temp;
}
printf("%s",s7);
return 0;
}