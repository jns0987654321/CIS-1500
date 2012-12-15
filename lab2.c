#include <stdio.h>
int main(void)

{

    double ac_TON, hours, SEER, cost, OPcost;

    //Reading in required input
    printf("Size of air conditioner: ");
    scanf ("%lf", &ac_TON);

    printf ("Estimated hours of use per year: ");
    scanf ("%lf", &hours);

    printf ("Air conditioner efficiency (SEER): ");
    scanf ("%lf", &SEER);

    printf ("Cost per kWh ($/kWh): ");
    scanf ("%lf", &cost);

    //Calculating operating cost of given A/c unit
    OPcost = ((ac_TON * 12000) / SEER / 1000);
    OPcost = OPcost * hours * cost;

    //Report the result
    printf("Estimated annual operating costs: $%.2f\n", OPcost);

return 0;

}

