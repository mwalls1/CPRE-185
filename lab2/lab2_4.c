#include <stdio.h>
#include <math.h>
int main()
{
	int a = 6427 + 1725;
	printf("6427 + 1725 = %d\n",a);
	int b = (6971*3925)-95;
	printf("(6971*3925)-95 = %d\n",b);
	double c = 79+12/5;
	printf("79 + 12/5 = %.2lf\n",c);
	double d = 3640.0/107.9;
	printf("3640.0/107.9 = %.2lf\n",d);
	int e = (22/3)*3;
	printf("(22/3)*3 = %d\n",e);
	int f = 22/(3*3);
	printf("22/(3*3) = %d\n",f);
	double g = 22/(3*3);
	printf("22/(3*3) = %.2lf\n",g);
	double h = 22/3*3;
	printf("22/3*3 = %.2lf\n",h);
	double i = (22.0/3)*3.0;
	printf("(22.0/3)*3.0 = %.2lf\n",i);
	int j = 22.0/(3*3.0);
	printf("22.0/(3*3.0) = %d\n",j);
	double k = 22.0/3.0*3.0;
	printf("22.0/3.0*3.0 = %.2lf\n",k);
	double circum = 23.657;
	double radius;
	double area;
	//Calculate radius by diving by 2 times pi
	radius = circum/(2*M_PI);
	//area of a circle is pi * radius squared
	area = M_PI*pow(radius,2);
	printf("The area of a circle with a circumfrence of %lf is %lf.\n",circum,area);
	//Feet to meters is feet/3.28 = meters
	double feet = 14.0;
	double meters;
	meters = feet/3.28;
	printf("%lf feet is %lf meters.",feet,meters);
	
	
	return 0;
}