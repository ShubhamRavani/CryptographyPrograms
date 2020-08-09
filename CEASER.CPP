#include<iostream.h>
#include<string.h>
#include<conio.h>

int main()
{
	clrscr();

	char msg[100],ch[100];
	int i,key,a;

		cout<<"Enter Plain Text : ";
		cin.getline(msg,100);
		cout<<"Enter Cipher Key : ";
		cin>>key;

		a=key/26;

		if(key>26)
		{
			key=key-a*26;
		}

		for(i=0;msg[i]!='\0';++i)
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
		cout<<"Encrypted Message : "<<ch;


	getch();
	return 0;

}


