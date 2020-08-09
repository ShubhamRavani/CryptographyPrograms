#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

class Crypto
{
	public:

	void ceaser();
	void monocipher();
	void polycipher();
	void railfence();
	void otp();
	void hillcipher();
	void columnar();
};

void Crypto::ceaser()
{
		clrscr();
		char msg[100],ch[100];
		int i,key,a;

		cout<<endl<<endl;
		cout<<"\t ***** Ceaser - Cipher *****"<<endl<<endl;

		cout<<"Enter Plain Text : ";
		cin>>msg;
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

}

void Crypto::monocipher()
{
		clrscr();

		int i,j;
		char pt[53]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		char cypt[53]={' ','q','l','m','w','o','p','k','r','s','z','j','i','h','g','f','e','d','c','b','a','t','y','x','u','v','n','Q','L','M','W','O','P','K','R','S','Z','J','I','H','G','F','E','D','C','B','A','T','Y','X','U','V','N'};

		char om[30],em[30];
		cout<<endl<<endl;
		cout<<"\t ***** Monoalphabetic - Cipher *****"<<endl<<endl;
		cout<<"Enter Plain Text : ";
		cin>>om;

		for(i=0;om[i]!=NULL;i++)
		{
			for(j=0;j<53;j++)
			{
				if(om[i]==pt[j])
				{
					em[i]=cypt[j];
				}
			}
		}

		em[i]=NULL;
		cout<<"Encrypted Message : "<<em;

}

void Crypto::polycipher()
{
	clrscr();
	char pt[40]={'10'}, key[40]={'10'}, ct[40]={'10'}, k[40]={'10'};
	int i,j;
	cout<<endl<<endl;
	cout<<"\t ***** Polyalphabetic - Cipher *****"<<endl<<endl;
	cout<<"Enter The Key Word : ";
	cin>>k;

	cout<<"Enter Plain Text : ";
	cin>>pt;

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

	cout<<"Encrypted Message : ";

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
			cout<<""<<ct[i];
		}

		else
		{
			ct[i]=pt[i];
			cout<<""<<pt[i];
		}

	}
}

void Crypto::railfence()
{
	clrscr();
	int i,j,k,l;
	char a[20],c[20];
	cout<<endl<<endl;
	cout<<"\t ***** Railfence - Cipher *****"<<endl<<endl;
		cout<<"Enter Plain Text : ";
		cin>>a;

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
		cout<<"Encrypted Message : ";
		cout<<""<<c;
}

void Crypto::otp()
{
	clrscr();
	int i,j,len1,len2,numstr[100],numkey[100],numcipher[100];
	char str[100],key[100],cipher[100];
	cout<<endl<<endl;
	cout<<"\t ***** One Time Pad Cipher *****"<<endl<<endl;
	cout<<"Enter Plain Text : ";
	cin>>str;

		for(i=0,j=0;i<strlen(str);i++)
		{
			if(str[i]!=' ')
			{
				str[j]=toupper(str[i]);
				j++;
			}
		}

	str[j]='\0';

		for(i=0;i<strlen(str);i++)
		{
			numstr[i]=str[i]-'A';
		}

	cout<<"Enter Key String of Random Text : ";
	cin>>key;

		for(i=0,j=0;i<strlen(key);i++)
		{
			if(key[i]!=' ')
			{
				key[j]=toupper(key[i]);
				j++;
			}
		}

	key[j]='\0';

		for(i=0;i<strlen(key);i++)
		{
			numkey[i]=key[i]-'A';
		}

		for(i=0;i<strlen(key);i++)
		{
			numcipher[i]=numstr[i]+numkey[i];
		}

		for(i=0;i<strlen(str);i++)
		{
			if(numcipher[i]>25)
			{
				numcipher[i]=numcipher[i]-26;
			}
		}

	cout<<"Encrypted Message : ";

		for(i=0;i<strlen(str);i++)
		{
			cout<<(numcipher[i]+'A');
		}

	cout<<endl;
}

void Crypto::hillcipher()
{
	clrscr();
	int i,j,ans[25][1],sum=0,mtrx[3][3],end;
	char txt[25],l;
	cout<<endl<<endl;
	cout<<"\t ***** Hill - Cipher *****"<<endl<<endl;
	cout<<"Enter Plain Text : ";
	cin>>txt;

	for(i=0;i<25;i++)
	{
		if(txt[i]>=97 && txt[i]<122)
		{

		}

		else
		{
			end=i;
			break;
		}
	}

	for(i=0;i<end;i++)
	{
		txt[i]=txt[i]-'a';
	}

	cout<<"\n Enter Matrix...\n";

	for(i=0;i<end;i++)
	{
		for(j=0;j<end;j++)
		{
			cin>>mtrx[i][j];
		}
	}
	cout<<endl;

    cout<<"Key matrix is :\n";

    for(i=0;i<end;i++)
	{
		for(j=0;j<end;j++)
		{
			cout<<mtrx[i][j];
		}
	cout<<endl;
    }

	for(i=0;i<end;i++)
	{
		sum=0;
		for(j=0;j<end;j++)
		{
			sum+=mtrx[i][j]*(int)txt[j];
		}

		ans[i][0]=sum;
	}

	for(i=0;i<end;i++)
	{
		l=((ans[i][0])%26)+97;
		cout<<l;
	}
}

int main()
{
	clrscr();

	int c;
	Crypto c1;
	char *yn;
	abc:

	cout<<"Enter Your Choice : "<<endl;
	cout<<"1. Ceaser Cipher."<<endl;
	cout<<"2. Monoalphabetic Cipher."<<endl;
	cout<<"3. Polyalphabetic Cipher."<<endl;
	cout<<"4. Rail Fence Cipher."<<endl;
	cout<<"5. One Time Pad Cipher."<<endl;
	cout<<"6. Hill Cipher."<<endl;
	//cout<<"7. PlayFair Cipher."<<endl;
       // cout<<"7. Columnar."<<endl;
	cout<<"7. Exit."<<endl<<endl;
	cin>>c;

	switch(c)
	{
		case 1:
			c1.ceaser();
		break;
		case 2:
			c1.monocipher();
		break;
		case 3:
			c1.polycipher();
		break;
		case 4:
			c1.railfence();
		break;
		case 5:
			c1.otp();
		break;
		case 6:
			c1.hillcipher();
		break;
		/*case 7:
			c1.playfair();
		break;
		case 7:
			c1.columnar();
		break; */
		case 7:
			exit(0);
	}

	cout<<endl<<endl;
	cout<<"Do you wish to continue..? (y/n) : "<<endl;
	cin>>yn;

	if(yn=="Y" || yn=="y")
	{
		goto abc;
	}
	else
	{
		exit(0);
	}

	getch();
	return 0;

}
