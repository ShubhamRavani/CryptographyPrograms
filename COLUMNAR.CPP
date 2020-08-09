#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

void main()
{
	char k[20]={'10'},pt[30]={'10'},key[30]={'10'},mat[10][10]={'10'},ct[30]={'10'};
	int i=0,j=0,no[10]={0},ctr,z,a=0;
	clrscr();

		printf("Enter the Plaintext : ");
		gets(pt);
		printf("Enter the Key : ");
		gets(k);

		strcpy(key,k);
		strcat(k,pt);
		strcpy(pt,k);

		printf("Enter the Ordering from 0 to the (keylength-1) : \n");
		for(i=0;i<strlen(key);i++)
		{
			scanf("%d",&no[i]);
		}

		j=0;
		ctr=j;

		printf("The Matrix : \n");
		for(i=0;i<strlen(pt);i++)
		{
			for(j=j;ctr<strlen(key);j++)
			{
				if(pt[j]!='\0')
				{
					mat[i][ctr]=pt[j];
					printf("%c",mat[i][ctr]);

					ctr++;
				}
				else
				{
					goto out;
				}
			}
			ctr=0;
			if(i==0)
			{
				printf("\n");
			}
			printf("\n");
		}

		out:

		printf("\n\n The Encrypted Text : \n");
		for(i=0;i<strlen(key);i++)
		{
			for(j=0;j<strlen(key);j++)
			{
				if(no[i]==j)
				{
					for(z=1;z<10;z++)
					{
						if(isalpha(mat[z][j]))
						{
							printf("%c",mat[z][j]);
							ct[a]=mat[z][j];
							a++;
						}
					}
				}
			}
		}
	getch();
}
