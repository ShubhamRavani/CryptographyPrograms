#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	int i,j,k,l;
	char a[20],c[20];
	clrscr();

		printf("Enter Plaintext : ");
		gets(a);

		l=strlen(a);

		for(i=0,j=0;i<l;i++)
		{
			if(i%2==0)
			{
				c[j++]=a[i];
			}
		}

		for(i=0;i<l;i++)
		{
			if(i%2==1)
			{
				c[j++]=a[i];
			}
		}

		c[j]='\0';
		printf("Ciphertext : ");
		printf("\n%s",c);

	getch();
}
