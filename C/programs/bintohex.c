#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	long int bin;
	int dec=0;
	int r,j,temp;
	int i=0;
	char str[10];


	printf("Enter binary number: ");
	scanf("%ld",&bin);

	while(bin!=0)
	{
		r=bin%10;
		dec=dec+r*pow(2,i);
		bin=bin/10;
		i++;
	}

	printf("Decimal: %d\n",dec);

	i=0;
	while(dec!=0)
	{
		r=dec%16;
		if(r<10)
		  str[i]=r+'0';
		else
		{
			if(r==10) str[i]='A';
			if(r==11) str[i]='B';
			if(r==12) str[i]='C';
			if(r==13) str[i]='D';
			if(r==14) str[i]='E';
			if(r==15) str[i]='F';
			/*temp=(r%10)+72;
			str[i]=temp+'0';*/
		}
		dec=dec/16;
		i++;
	}

	printf("Hexadecimal Number: ");

	for(j=i-1;j>-1;j--)
		printf("%c",str[j]);

	return 0;
	
}

