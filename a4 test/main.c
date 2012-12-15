#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>




int main(void)
{
	char ISBN[14];
	int size=1, i=0, digit=0, ISBN_int[14];

	while (size !=14)
	{
	printf("Enter string");
	fgets(ISBN,20,stdin);
	size = strlen(ISBN);
	if (strlen(ISBN) <14 || strlen(ISBN) >14)
		printf("Please enter only 13 digits!!\n");
	}
	
	for(i=0; i<13; i++)
	{   
		if(isdigit(ISBN[i]))
		digit++;
	}
	
	if(digit !=13)
	printf("Please enter only numbers!!");
	
	
	for (i=0; i<13; i++)
	{
		ISBN_int[i] =(ISBN[i]-48);
		printf("%d", ISBN_int[i]);
	}
	
	
	return 0;
	
	
}