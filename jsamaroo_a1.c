/*
 
 ASSIGNMENT: CIS 1500 Assignment #1
 PROGRAM NAME: Orbital Velocity Calculator
 AUTHOR: Junior Samaroo
 STUDENT ID # 0663108
 DATE CREATED: 2nd October, 2009
 DATE UPDATED: 3rd October, 2009
 
 DESCRIPTION: The program was designed to calculate the orbital velocity of a satellite around the earth in kilometres per second (km/s).
 
 ALGORITHM ANALYSIS:
 Input: The program requires the user to input the altitude of the satellite above the earth in kilometres (km).
 Output: The program outputs the orbital velocity of the satellite in kilometres per second (km/s).
 
 ALGORITHM DESIGN: The program first asks the user to input the altitude of the satellite above te earth in kilometres (km).
 It then reads this data and if the height entered is <320km the program displays an error message and the orbital velocity 
 is not calculated. If the altitude entered is >=320km the program continues calculating the orbital velocity. It first calculates 
 the distance from the satellite to the centre of the earth "r", in metres (m). The orbital velocity is then calculated in metres 
 per second (m/s), which is then converted to kilometres per second (km/s). Finally the program outputs the velocity of the satellite
 in kilometres per second (km/s) to 2 decimal places.
 
 */

#include <stdio.h>
#include <math.h>
#define G 6.67e-11   // Universal gravitational constant (Nm^2/kg^2)
#define Re 6378      // mean earth radius in kilometres (km)
#define M 5.98e24    // mass of planet(earth) in kilograms (kg)

int main(void)
{	
	// Declaration of variables	
	double Vc;  // orbital velocity of satellite in metres per second (m/s)
	double r;   // distance from the satellite to the centre of earth in metres (m)
	double h;   // altitude of satellite above the surface of the earth in kilometres (km)
	
	// User Input
	printf("Please enter altitude of satelite above the earth's surface in kilometres (km) :");
	scanf("%lf", &h);
	
	// Calculations
	if (h<320)
	    {
	    printf("Error: Altitude of satellite entered is <320km which would cause it to crash! \n");
	    return 0;
	    }
	else
	// Calculation of distance of satellite to centre of earth in metres (m)
	r = (Re + h)*1000;
	// Calculation of orbital velocity in kilometres per second (km/s)
	Vc = ((G*M)/r);
	Vc = (sqrt(Vc))/1000;
	
	// Output of calculated information
	printf("Velocity of satellite is %.2f km/s \n", Vc);

	return 0;
	
}
