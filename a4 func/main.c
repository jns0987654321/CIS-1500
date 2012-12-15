/*
 
 ASSIGNMENT: CIS 1500 Assignment #4
 PROGRAM NAME: 13-digit ISBN validity calculator
 AUTHOR: Junior Samaroo
 STUDENT ID # 0663108
 DATE CREATED: 23rd November, 2009
 DATE UPDATED: 24th November, 2009
 
 DESCRIPTION: The program was designed to calculate 13-digit ISBN number checksums and determine if the number is valid or not.
 
 ALGORITHM ANALYSIS:
 Input: The program requires the user to input the full 13-digit ISBN number in succession.
 Output: The program then outputs whether the ISBN number entered was valid or not.
 
 ALGORITHM DESIGN: The program first checks the constraints of the input data. Once the correct input is received by the "read_ISBN"
 function it converts the 13-digit ISBN number to an interger array and returns it to the main function . The function "is_valid" then reads 
 the ISBN number calling upon the function "check_sum" which takes the ISBN number as input returning the checksum digit to the
 function "is_valid". This function then determines whether the ISBN number entered is valid using the calculated checksum digit.
 
 KNOWN ISSUES: If the ISBN number entered is >18 digits the program will display the error message more than once before prompting
 the user to enter the ISBN again since "fgets" reads 20 characters.
 
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void is_valid(int ISBN_int[]);                   // Prototype of function that checks ISBN number validity
int check_sum(int ISBN_int[]);                   // Prototype of function that calculates the checksum of the ISBN number
void read_ISBN(char ISBN[], int ISBN_int[]);     // Prototype of function that reads in the 13-digit ISBN number


int main(void)
{
	char ISBN[14];       // Character array that stores user input
	int  ISBN_int[14];   // Array that stores ISBN number as intergers
	
	// Call the function 'read_ISBN' with its required parameters
	read_ISBN(ISBN, ISBN_int);
	
	// Call the function 'is_valid' with its required parameters
	is_valid(ISBN_int);
	
	return 0;	
}

// Function that reads in the 13-digit ISBN number
void read_ISBN(char ISBN[], int ISBN_int[])
{
	int size=1;   // Stores length of string
	int i=0;      // Check variable for loop
	int digit=0;  // Stores number of digits only in ISBN number
	
	// Input and defensive programming loop
	while (size !=14)
	{
		while (size !=14)
		{
			printf("\nPlease enter a 13-digit ISBN number:");
			fgets(ISBN,20,stdin);
			size = strlen(ISBN);
			
			if (strlen(ISBN) <14 || strlen(ISBN) >14)
				printf("\nISBN number must be exactly 13-digits long! Try again!\n");
		}
		
		for(i=0; i<13; i++)
		{   
			if(isdigit(ISBN[i]))
				digit++;
		}
		
		if(digit !=13)
		{
			printf("\nISBN number must contain only digits! Try again!\n");
			digit=0;
			size=0;
		}
		
	}
	// Conversion of characters of string to intergers
	for (i=0; i<13; i++)
		ISBN_int[i] =(ISBN[i]-48);
	
}

// Function that calculates the checksum of the ISBN number
int check_sum(int ISBN_int[])
{
	int i=0;         // Check variable for loop
	int digit13=0;   // Stores the 13th digit (checksum digit)
	
	for(i=0; i<12; i++)
	{
		if( i%2==0)
		    digit13 = digit13 + ISBN_int[i];
		else if (i%2==1)
			digit13 = digit13 + (ISBN_int[i]*3);
	}
	digit13 = 10-(digit13%10);
	
	if(digit13==10)
		digit13=0;
	
	return digit13;
	
}

// Function that checks ISBN number validity
void is_valid(int ISBN_int[])
{
	int digit13;   // Stores the 13th digit (checksum digit)
	
	// Call the function 'check_sum' with its required parameters
	digit13 = check_sum(ISBN_int);
	
	// Output of calculated data returned from the 'check_sum' function
	if (digit13 == ISBN_int[12])
		printf("\nISBN number entered is valid! Correct checksum!");
	else
		printf("\nISBN number entered is not valid! Incorrect checksum!");	
	
}



