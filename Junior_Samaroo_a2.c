/*
 
 ASSIGNMENT: CIS 1500 Assignment #2
 PROGRAM NAME: Dam force calculator
 AUTHOR: Junior Samaroo
 STUDENT ID # 0663108
 DATE CREATED: 22nd October, 2009
 DATE UPDATED: 24th October, 2009
 
 DESCRIPTION: The program was designed to calculate the force exerted on a simple vertical dam in kN(kiloneutons) and kN/unit
 and the position of this force from the water surface.
 
 ALGORITHM ANALYSIS:
 Input: The program firsts requires the user to select the units to be used for the input of data.
 The user then inputs the length/width and depth of the dam in either metric(metres) or imperial(feet) units based on the unit selected.
 Output: The program outputs the force exerted on the dam in kN and kN/unit and the position of this force from the water surface.
 
 ALGORITHM DESIGN: Based on the type of unit selected the program takes 2 paths. If the unit selected is metres the program checks to
 see if the input is correct via defensive programming and then goes into calculation. It calculates the force on the dam in 
 kiloneutons, the force per unit area(metres) and the distance of the force from the water surface in meters and outputs this information.
 The second path the program takes is if the user selects to input data in imperial units. It then also checks to see if the input is correct
 via defensive programming and continues to the calculations. The program then converts feet to metres to calculate the force on dam and 
 the force per unit area(feet). It then outputs this information and the distance of the force from the water surface in feet.
 
 KNOWN ISSUES: If a character is entered instead of a number for the input of the dimensions of the dam it goes into an infinite loop.
 
 */

#include <stdio.h>
#include <math.h>
#define rho 1000   // Density of water (1000 kg/m^3)
#define g 9.81     // Gravity Constant (9.81 m/s^2)

int main (void)
{
	// Declaration of variables
    double Force;     // Force exerted on dam in kN(kiloneutons)
	double Force_u;   // Force exerted on dam in kN/unit (unit either m^2 of ft^2)
	double area;      // Area of face of dam (m^2 or ft^2)
	double depth=0;   // Depth of water in dam (m or ft)
	double base=-1;   // Width/length of dam (m or ft)
	double pos_Force; // Position of force from water surface i.e centre of pressure (m or ft)
	char ch;          // Choice of unit choosen (metric or imperial)
	
	// Selection of units and input of data
	printf("Do you wish to input in (a) metric<metres> or (b) imperial<feet> units?\n");
	scanf("%c", &ch);
	
	if(ch =='a' || ch=='b')
	{
		// Loop to perform defensive progamming
		while (depth <= 0)
		{
			printf("Please enter depth of dam: ");
			scanf("%lf", &depth);
			if (depth <= 0) 
			{
				printf("Depth of dam must be greater than zero!\n");
			}
		}
		// Loop to perform defensive programming
		while(base <=-1)
		{
			printf("Please enter length/width of dam: ");
			scanf("%lf", &base);
			if (base <= -1) 
			{
				printf("Length/width of dam must be greater than or equal to zero!\n");
			}
		}
	}
	else 
	    {
		printf("Wrong selection made! Please try again!\n");
	    }
	
	// Calculations of metric user input
	if (ch== 'a')
	{   
		if (base==0) 
		{
			base=1;
		}
		area = depth*base;
		Force = (rho*g*area*(depth/2))/1000;
		Force_u = Force/area;
		pos_Force = (2*depth)/3;
		// Output of calculated information
		printf("Force on dam is %.0f kN\n", Force);
		printf("Force on dam per unit is %.1f kN/m^2\n", Force_u);
		printf("Position of force is %.2f m below the water surface\n", pos_Force);
	}
	
	// Conversion and calcualtion of imperial user input 
	else if (ch== 'b') 
	{
		if (base==0) 
		{
			base=(1/0.3048);
		}
		area = (depth*0.3048)*(base*0.3048);
		Force = (rho*g*area*((depth*0.3048)/2))/1000;
		Force_u = Force/area;
		pos_Force = (2*depth)/3;
		// Output of calculated information
		printf("Force on dam is %.0f kN\n", Force);
		printf("Force on dam per unit is %.1f kN/ft^2\n", Force_u);
		printf("Position of force is %.2f ft below the water surface\n", pos_Force);
	}
	
	return 0;
}