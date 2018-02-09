/*-----------------------------------------------------------------------------
-					          185 Lab 02
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-							 Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double a, b, c;
    double filler;
    /* Put your code after this line */
	printf("Enter side length 'a' of the triangle: ");
	scanf(" %lf",&a);
	printf("Enter side length 'b' of the triangle: ");
	scanf(" %lf",&b);
	c = pow(a,2)+pow(b,2);

    /*  This next line will calculate the square root of whatever value is
        inside the parenthesis and assigns it to the variable filler. */
    filler = sqrt(c);
	c = filler;
	printf("\nA triangle with a = %lf and b = %lf, will have c = %lf",a,b,c);



    return 0;


}

