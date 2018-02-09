/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */
int numButtons(int a, int b, int c, int d);
int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int triangle, circle, x, square;    


    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
        scanf("%d,%d,%d,%d", &triangle, &circle, &x, &square); 
		
		printf("The number of buttons currently pressed is: %d\n",numButtons(triangle,circle,x,square));
		fflush(stdout);
    }

return 0;
}

/* Put your functions here */
int numButtons(int a, int b, int c, int d)
{
	return a+b+c+d;
}

