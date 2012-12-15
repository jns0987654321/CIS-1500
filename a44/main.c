#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>




int main(void)
{
	char ISBN[14];
	int size=1, i=0, digit=0, ISBN_int[14], checksum;
	
	while (size !=14)
	{
	while (size !=14)
	{
		printf("\nEnter string");
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
	
		if(digit !=13){
		printf("Please enter only numbers!!\n");
			size =1;
			digit=0;
			size=0;
		}
	}

	
	
	for (i=0; i<13; i++)
	{
		ISBN_int[i] =(ISBN[i]-48);
		printf("%d", ISBN_int[i]);
	}
	
	checksum = ISBN_int[0] + (ISBN_int[1]*3) + ISBN_int[2] + (ISBN_int[3]*3) + ISBN_int[4] + (ISBN_int[5]*3) + ISBN_int[6] + (ISBN_int[7]*3) + ISBN_int[8] + (ISBN_int[9]*3) + ISBN_int[10] + (ISBN_int[11]*3);
	checksum = 10-(checksum%10);
	if(checksum==10){
		checksum=0;
	}	
	
	printf("\n%d\n", checksum);
	
	if (checksum == ISBN_int[12])
		printf("\n valid!!!");
	else
		printf("\n not valid!!");
	
	
				
	return 0;
	
	
}