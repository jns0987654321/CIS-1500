#include <stdio.h>
// Program to calculate annual operating costs of running
// air conditioning
int main(void)
{
	double ac_TONs, hours, SEER, cost, OPcost;
	// Input parameters
	printf(“Size of air conditioner: “);
	scanf(“%lf”, &ac_TONs);
	printf(“Estimated hours of use per year: “);
	scanf(“%lf”, &hours);
	printf(“Air conditioner efficiency (SEER): “);
	scanf(“%lf”, &SEER);
	printf(“Cost per kWh ($/kWh): “);
	scanf(“%lf”, &cost);
	// Calculate the air conditioning operating costs
	OPcost = (ac_TONs * 12000.0) / SEER / 1000.0;
	OPcost = OPcost * hours * cost;
	printf(“Estimated annual operating costs: $%.2f\n”, OPcost);
	return 0;
}