#include<stdio.h>
#include<conio.h>
#include<string.h>

char pt[40]={'10'}, key[40]={'10'}, ct[40]={'10'}, pta[40]={'10'}, k[40]={'10'};
int i,j;

void main()
{
	clrscr();

	printf("Enter The Key Word : ");
	gets(k);

	printf("Enter The Plain Text : ");
	gets(pt);

	j=0;

	for(i=0;i<strlen(pt);i++)
	{
		key[i]=k[j];
		if(j==(strlen(k)-1))
		{
			j=0;
		}
		else
		{
			j++;
		}
	}

	for(i=0;i<strlen(pt)-1;i++)
	{
		k[i]='10';
	}

	printf("The Encrypted Text Is : ");

	for(i=0;i<strlen(pt);i++)
	{
		if(((int)pt[i]>=97) && ((int)pt[i]<=122))
		{
			if((int)pt[i]+(int)key[i]>219)
			{
				ct[i]=(int)pt[i]+(int)key[i]-123;
			}
			else
			{
				ct[i]=(int)pt[i]+(int)key[i]-97;
			}
			printf("%c",ct[i]);
		}

		else
		{
			ct[i]=pt[i];
			printf("%c",pt[i]);
		}

	}
	getch();
}