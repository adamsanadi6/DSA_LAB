#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void read();
void display();
void pattern();

char mainstr[100],patstr[100],repstr[100],tempstr[100];

void main()
{
	read();
	printf("String before pattern match:");
	puts(mainstr);
	display();
	pattern();
	printf("String After pattern match:");
	puts(mainstr);
}

void read()
{
	printf("Enter the main string ,pattern string and replacement string respectively:\n");
	gets(mainstr);
	gets(patstr);
	gets(repstr);
}

void display()
{
	printf("The entered main string ,pattern string and replacement string are:\n");
	puts(mainstr);
	puts(patstr);
	puts(repstr);
}

void pattern()
{
	int mi=0,pi=0,ti=0,ci=0,ri=0,flag=0;
	while(mainstr[mi]!='\0')
	{
		while((mainstr[ci]==patstr[pi])&&((mainstr[ci]!='\0')||(patstr[pi]!='\0')))
		{
			ci++;
			pi++;
		}
		if(patstr[pi]=='\0')
		{
			
			for(ri=0;repstr[ri]!='\0';ri++)
			{
				tempstr[ti]=repstr[ri];
				ti++;
			}
			mi=ci;
			pi=0;
			flag=1;
		}
		tempstr[ti]=mainstr[mi];
		mi++;
		ci=mi;
		pi=0;
		ti++;		
	}
	if(flag==0)
	{
		printf("Pattern does not found.\n");
	}
	else
	{
		tempstr[ti]='\0';
		for(ti=0;tempstr[ti]!=0;ti++)
			mainstr[ti]=tempstr[ti];
		mainstr[ti]='\0';
	}
}
