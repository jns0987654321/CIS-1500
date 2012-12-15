#include <stdio.h>
#include <math.h>


int main (void) 
{
	double Hn[100], Pn[100], k, c, a;
	int n, i;
	printf("how many generations?");
	scanf("%d", &n);
	printf("a?");
	scanf("%lf", &a);
	printf("c?");
	scanf("%lf", &c);
	printf("k?");
	scanf("%lf", &k);
	printf("initial host?");
	scanf("%lf", &Hn[0]);
	printf("initial parasite");
	scanf("%lf", &Pn[0]);
	
	printf("Gen       Host    Parasitoid\n");
	for (i=0; i<n; i++)
	{
		Hn[i+1]=k*Hn[i]*(exp(-a*Pn[i]));
		Pn[i+1]=c*Hn[i]*(1-exp(-a*Pn[i]));
		
	}
	for (i=0; i<n; i++)
		printf("%3d  %9.4lf  %12.4lf\n", i+1, Hn[i], Pn[i]);
	
	
	return 0;
	
	
}



