/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */
double mag(double a, double b, double c);
int minutes(int a);
int seconds(int a);
int millis(int a);
int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double  ax, ay, az;     


    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
        scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az); 

/* CODE SECTION 0 */
        //printf("Echoing output: %8.3lf, %7.3lf, %7.3lf, %7.3lf\n", t/1000.0, ax, ay, az);

/* CODE SECTION 1 */
        /*printf("At %d ms, the acceleration's magnitude was: %lf\n", 
            t, mag(ax, ay, az));*/
            
/* CODE SECTION 2 */
        printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
        minutes(t), seconds(t), millis(t), mag(ax,ay,az));

    }

return 0;
}

/* Put your functions here */
double mag(double a, double b, double c)
{
	return sqrt(pow(a,2)+pow(b,2)+pow(c,2));
}
int minutes(int a)
{
	return a/60000;
}
int seconds(int a)
{
	return (a/1000)%60;
}
int millis(int a)
{
	return a%1000;
}


