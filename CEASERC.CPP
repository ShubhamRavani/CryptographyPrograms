#include<stdio.h>
#include<string.h>
#include<conio.h>

int main()
{
	clrscr();

	char msg[100],ch[100];
	int i,key,c;

		printf("Enter Plain Text : ");
		gets(msg);
		printf("Enter Cipher Key : ");
		scanf("%d",&key);

		c=key/26;
		if(key>26)
		{
			key=key-(c*26);
		}

		for(i=0;msg[i]!='\0';i++)
		{
			if(msg[i]==' ')
			{
				ch[i]=' ';
			}

			else if(msg[i]>='a' && msg[i]<='z')
			{
				ch[i]=msg[i]+key;

				if(ch[i]>'z'|| ch[i]<0)
				{
					ch[i]=ch[i]-26;
				}


			}

			else
			{
				ch[i]=msg[i]+key;

				if(ch[i]>'Z')
				{
					ch[i]=ch[i]-26;
				}


			}

		}

		ch[i]=NULL;

		printf("Encrypted Message : %s",ch);


	getch();
	return 0;

}


