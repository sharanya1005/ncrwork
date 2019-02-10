#include<stdio.h>
#include<math.h>
#include<string.h>

void itob(int,char[]);
void itoh(int,char[]);

int main()
{
	int n;
	int dec=0;
	int r,i=0;
	char res1[10];
	char res2[10];

	printf("Enter n: ");
	scanf("%d",&n);

	itob(n,res1);
	printf("Binary: %s\n",res1);

	itoh(n,res2);
	printf("Hexadecimal: %s\n",res2);

	return 0;


}

void itob(int dec,char *s1)
{
	char bin[10];
	char revbin[10];
	int i=0;
	int r,j,k;

	while(dec!=0)
	{
		r=dec%2;
		bin[i]=r+'0';
		dec=dec/2;
		i++;
	}
	
	for(k=0,j=i-1;j>-1;k++,j--)
		revbin[k]=bin[j];
	revbin[k]='\0';
	//printf("bin = %s\n",bin);
	//printf("revbin = %s\n",revbin);
	strcpy(s1,revbin);		
}

void itoh(int dec,char *s2)
{
	char hex[10];
	char revhex[10];
	int r,k,j,i=0;

	while(dec!=0)
	{
		r=dec%16;
		if(r<10)
			hex[i]=r+'0';
		if(r>=10)
			hex[i]=r+'57';
		dec=dec/16;
		i++;
	}

	for(j=i-1,k=0;j>-1;j--,k++)
		revhex[k]=hex[j];
	revhex[k]='\0';
	//printf("hex = %s\n",hex);
	//printf("revhex = %s\n",revhex);
	strcpy(s2,revhex);
}
