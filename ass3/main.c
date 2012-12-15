#include <stdio.h>
#include <math.h>


double NB(double n, double Hn, double Pn, double k, double c, double a)
{
	
	int i=1;
	double Hn2, Pn2, x;
	printf("Gen       Host    Parasitoid\n");
	printf("%3d  %9.4lf  %12.4lf\n", i, Hn, Pn);
	for (i=2; i<n+1; i++)
	{
		Hn2=k*Hn*(exp(-a*Pn));
		Pn2=c*Hn*(1-exp(-a*Pn));
		printf("%3d  %9.4lf  %12.4lf\n", i, Hn2, Pn2);
		Hn=Hn2;
		Pn=Pn2;
	}
	return x;
}


int main (void) 
{
	double Hn, Pn, k, c, a, x;
	int n;
	printf("how many generations?");
	scanf("%d", &n);
	printf("a?");
	scanf("%lf", &a);
	printf("c?");
	scanf("%lf", &c);
	printf("k?");
	scanf("%lf", &k);
	printf("initial host?");
	scanf("%lf", &Hn);
	printf("initial parasite");
	scanf("%lf", &Pn);
	
	x= NB(n,Hn,Pn,k,c,a);
	
	return 0;

}



