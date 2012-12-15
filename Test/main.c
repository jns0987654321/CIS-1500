/*
 
 ASSIGNMENT: CIS 1500 Assignment #3
 PROGRAM NAME: Nicholson Bailey model generator
 AUTHOR: Junior Samaroo
 STUDENT ID # 0663108
 DATE CREATED: 8th November, 2009
 DATE UPDATED: 9th November, 2009
 
 DESCRIPTION: The program was designed to generate results for the Nicholson-Bailey model over a series of "n" gernations.
 
 ALGORITHM ANALYSIS:
 Input: The program requires the user to input the number of generations to calculate results, the searching efficiency 
 constant of the parasitoid, the average number of eggs deposited by the parasitoid on a single host, the reproductive 
 rate of the host, initial host density and the initial parasite density.
 Output: The program then outputs the population density of the host and parasitoid of each generation in a table format.
 
 
 ALGORITHM DESIGN: The program first checks the constraints of the input data. Once the input has been received it calls upon the
 Nicholson Bailey function with its required parameters. This function then calculates the population density of the host and parasitoid 
 at each generation and stores it in its respective array, where it is returned to the main fuction. The main fuction then prints the
 results of the Nicholson Bailey fuction in a table format.
 
 KNOWN ISSUES: Could only generate results for the Nicholson Bailey model over a maximum of 100 generations since the population density 
 arrays of the host and parasitoid were declared with a size of 100.
 
 */


#include <stdio.h>
#include <math.h>

// Function "Nicholson_Bailey" to generate results over "n" generations
double N_Bailey(double H_density[], double P_density[], double R_rate, double Avg_Eggs, double Search_Eff, int n)

{   
	// Loop to calculate population density of host and parasitoid at each generation
	int i;
	for (i=0; i<n; i++)
	{
	    H_density[i+1]=R_rate*H_density[i]*(exp(-Search_Eff*P_density[i]));
	    P_density[i+1]=Avg_Eggs*H_density[i]*(1-exp(-Search_Eff*P_density[i]));
		
	}
	
	// Returns population density arrays of host and parasitoid to main function to be printed
	return H_density[100];
	return P_density[100];	
}


int main (void) 

{
	double H_density[100];  // Array that holds population density of host up to 100 generations
	double P_density[100];  // Array that holds population density of parasitoid up to 100 generations
	double R_rate=0;        // Reproductive rate of host
	double Avg_Eggs=0;      // Average number of viable eggs deposited by parasitoid on a single host
	double Search_Eff=0;    // Searching efficiency constant of parasitoid
	double Pop_Density;     // Population density variable to which the host and parasitoid arrays are returned to
	int n;                  // Number of generations to calculate
	int i;                  // Check variable for loop
	
	// Input and defensive programming loop
	while (n<=0 || n>100)
	{
	    printf("How many generations do you wish to calculate?");
	    scanf("%d", &n);
		if (n<=0 || n>100)
		    printf("Error: Number of generations entered must be >0 but <=100 !\n");
	}
	
	// Input and defensive programming loop
	while (Search_Eff<=0)
	{
	    printf("PLease enter the searching efficiency constant of the parasitoid :");
	    scanf("%lf", &Search_Eff);
		if (Search_Eff<=0)
		    printf("Error: searching efficiency constant must be greater than zero!\n");
	}
	
	// Input and defensive programming loop
	while (Avg_Eggs<=0)
	{
	    printf("Please enter the average number of eggs deposited by the parasitoid on a single host :");
		scanf("%lf", &Avg_Eggs);
		if (Avg_Eggs<=0)
		    printf("Error: number of eggs deposited must be greater than zero!\n");
	}
	
	// Input and defensive programming loop
	while (R_rate<=0)
	{
	    printf("Please enter reproductive rate of the host :");
	    scanf("%lf", &R_rate);
		if (R_rate<=0)
		    printf("Error: reproductive rate of host must be greater than zero!\n");
	}
	
	// Input and defensive programming loop
	H_density[0]=0;
	while (H_density[0]<=0)
	{
	    printf("Please enter initial host density :");
	    scanf("%lf", &H_density[0]);
		if (H_density<=0)
		    printf("Error: initial host density must be greater than zero!\n");
	}
	
	// Input and defensive programming loop
	P_density[0]=0;
	while (P_density[0]<=0)
	{
	    printf("Please enter initial parasite density :");
	    scanf("%lf", &P_density[0]);
		if (P_density<=0)
		    printf("Error: initial parasite density must be greater than zero!\n");
	}
	
	// Call the function Nicholson_Bailey with its required parameters
	Pop_Density = N_Bailey(H_density,P_density, R_rate, Avg_Eggs, Search_Eff, n);
	
	// Output of calculated data returned from the Nicholson_Bailey function
	printf("\nGen       Host    Parasitoid\n");
	for (i=0; i<n; i++)
	    printf("%3d  %9.4lf  %12.4lf\n", i+1, H_density[i], P_density[i]);
	
	
	return 0;
	
}



