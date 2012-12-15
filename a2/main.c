#include <stdio.h>
#include <math.h>
#define rho 1000
#define g 9.81

int main (void)
{
    double Force, Force_u, area, depth=0, base=-1, pos_Force;
	char ch;
	
	printf("Do you wish to calculate in (a) metric or (b) imperial?\n");
	scanf("%c", &ch);
	
	if(ch =='a' || ch=='b')
	{
		while(depth <= 0)
		{
			printf("Please enter depth of dam: ");
			scanf("%lf", &depth);
			if (depth <= 0) 
			{
				printf("Depth of dam must be greater than zero!\n");
			}
		}
		
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
		printf("Wrong selection made! Please try again!\n");
	
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
		printf("Force on dam is %.0f kN\n", Force);
		printf("Force on dam per unit is %.1f kN/m^2\n", Force_u);
		printf("Position of force is %.2f m below the water surface\n", pos_Force);
	}
	
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
		printf("Force on dam is %.0f kN\n", Force);
		printf("Force on dam per unit is %.1f kN/ft^2\n", Force_u);
		printf("Position of force is %.2f ft below the water surface\n", pos_Force);
	}
	
	return 0;
}