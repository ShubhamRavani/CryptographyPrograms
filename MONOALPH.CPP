#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	clrscr();

	randomize();

		int i,j;

		char msg[100],ch[100];

			cout<<"Enter Plain Text : ";
			cin.getline(msg,100);

				for(i=0;msg[i]!=NULL;i++)
				{
					if(msg[i]==' ')
					{
						ch[i]=' ';
					}

					else if(msg[i]>='a' && msg[i]<='z')
					{
						ch[i]=msg[i]+random(53);

						if(ch[i]>'z' || ch[i]<0)
						{
							ch[i]=ch[i]-26;
						}
					}

					else
					{
						ch[i]=msg[i]+random(53);

						if(ch[i]>'Z')
						{
							ch[i]=ch[i]-26;
						}
					}

				}

				ch[i]=NULL;

			cout<<"\n Encrypted Text : "<<ch;

	getch();

}
