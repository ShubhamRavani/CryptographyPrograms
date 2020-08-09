#include<stdio.h>
#include<conio.h>
#include<string.h>

char km[5][5], om[30],em[30],key[26],c='i',msg[30],msg1[30];
int ki,i,j,k=0,f=0,z=0,l,aa,r1,c1,c2,r2,zz=0;
char rm[26];
char ab[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void main()
{
	clrscr();

		printf("Enter Key : ");
		gets(key);

		for(i=0;key[i]!=NULL;i++)
		{
			if(key[i]!=' ')
			{
				for(j=0,f=0;rm[j]!=NULL;j++)
				{
					if(key[i]==rm[j])
					{
						f=1;
						break;
					}
				}
				if(f!=1)
				{
					rm[k]=key[i];
					k++;
				}
				if(z==0)
				{
					if(key[i]=='i' || key[i]=='j')
					{
						c=key[i];
						z++;
					}
				}
			}
		}

		for(i=0;i<26;i++)
		{
			for(j=0,f=0;j<k;j++)
			{
				if(ab[i]==rm[j])
				{
					f=1;
					break;
				}
			}
			if(f!=1)
			{
				rm[k]=ab[i];
				k++;
			}
		}

		rm[k]=NULL;

		if(c=='i')
		{
			c++;
		}
		else
		{
			c--;
		}

		for(i=0;rm[i]!=NULL;i++)
		{
			if(rm[i]==c)
			{
				k=i;
				break;
			}
		}

		for(i=k,j=i+1;rm[i]!=NULL;i++,j++)
		{
			if(i==25)
			{
				break;
			}
			rm[i]=rm[j];
		}

		k=0;

		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				km[i][j]=rm[k];
				k++;
			}
		}

		printf("Matrix Key  : \n");

		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				printf("%c",km[i][j]);
			}
			printf("\n");
		}

		printf("\n Enter Plaintext Message : ");
		gets(om);

		for(i=0,j=0;om[i]!=NULL;i++)
		{
			if(om[i]!=' ')
			{
				msg[j]=om[i];
				j++;
			}
		}

		msg[j]=NULL;
		l=strlen(msg);

		if(l%2==1)
		{
			msg[l]='x';
			msg[l+1]=NULL;
		}

		puts(msg);
		l=strlen(msg);
		aa=l+((1/2)-1);

		for(i=l-1,k=1;aa-1>=0;k++)
		{
			if(k%3==0)
			{
				msg1[aa-1]=' ';
				aa--;
			}
			else
			{
				msg1[aa-1]=msg[i];
				aa--;
				i--;
			}
		}

		msg1[k]=NULL;

		for(i=1;msg1[i-1]!=NULL;i++)
		{
			if(i%3==0)
			{
				continue;
			}
			if(msg1[i-1]==msg1[i])
			{
				msg1[i]='x';
			}
		}

		printf("%s",msg1);
		l=strlen(msg1);

		for(i=1,ki=1;i<=l+1;i++)
		{
			if(i%3==0)
			{
				if(r1==r2)
				{
					if(c1==4)
					{
						c1=0;
					}
					else
					{
						c1++;
					}

					if(c2==4)
					{
						c2=0;
					}
					else
					{
						c2++;
					}
					em[zz]=km[r1][c1];
					zz++;
					em[zz]=km[r2][c2];
					zz++;
				}
				else if(c1==c2)
				{
					if(r1==4)
					{
						r1=0;
					}
					else
					{
						r1++;
					}

					if(r2==4)
					{
						r2=0;
					}
					else
					{
						r2++;
					}
					em[zz]=km[r1][c1];
					zz++;
					em[zz]=km[r2][c2];
					zz++;
				}
				else
				{
					em[zz]=km[r1][c2];
					zz++;
					em[zz]=km[r2][c1];
					zz++;
				}

				continue;
			}

			for(j=0;j<5;j++)
			{
				for(k=0;k<5;k++)
				{
					if(msg1[i-1]==km[j][k])
					{
						if(ki%2==0)
						{
							r2=j;
							c2=k;
							ki++;
						}
						else
						{
							r1=j;
							c1=k;
							ki++;
						}
					}
				}
			}
		}

		printf("\n Encrypted Message : %s",em);
	getch();
}