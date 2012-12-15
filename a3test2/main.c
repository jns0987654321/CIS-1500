#include <stdio.h>
#include <math.h>

double NB(double Hn[], double Pn[], double k, double c, double a, int n)
{
	for (int i=0; i<n; i++)
	{
		Hn[i+1]=k*(Hn[i])*(exp(-a*(Pn[i])));
		Pn[i+1]=c*(Hn[i])*(1-exp(-a*(Pn[i])));
		
	}
	return Hn[100];
	
}



int main (void) 
{
	double Hn[100];
	double Pn[100];
	double k, c, a, x;
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
	 
	x = NB(Hn, Pn, k, c, a, n);
	
	printf("Gen       Host    Parasitoid\n");
		for (i=0; i<n; i++)
		printf("%3d  %9.4lf  %12.4lf\n", i+1, Hn[i], x);
	
	
	return 0;
		
}



