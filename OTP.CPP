#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

void main()
{
	int i,j,len1,len2,numstr[100],numkey[100],numcipher[100];
	char str[100],key[100],cipher[100];

	printf("Enter a String Text to Encrypt : ");
	gets(str);

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

	printf("Enter Key String of Random Text : ");
	gets(key);

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

	printf("One Time Pad Cipher Text : ");

		for(i=0;i<strlen(str);i++)
		{
			printf("%c",(numcipher[i]+'A'));
		}

	printf("\n");

	getch();
}