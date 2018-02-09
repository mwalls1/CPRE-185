// 185 Lab 7
#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);
double avg(double buffer[], int num_items)
{
	int i = 0;
	double average;
	for(i = 0; i < num_items; i++)
	{
		average+=buffer[i];
	}
	return (average/(1.0*num_items));
}

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);
void maxmin(double array[], int num_items, double* max, double* min)
{
	*min = array[0];
	*max = array[0];
	int i = 0;
	for(i=0; i < num_items; i++)
	{
		if(array[i]>*max)
			*max=array[i];
		else if(array[i]<*min)
			*min = array[i];
	}
}
//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);
void updatebuffer(double buffer[], int length, double new_item)
{
	int i = 0;
	for(i = length-2; i>=0; i--)
	{
		buffer[i+1] = buffer[i];
	}
	buffer[0] = new_item;
}


int main(int argc, char* argv[]) {
	
	/* DO NOT CHANGE THIS PART OF THE CODE */
	int bT, bC, bX, bS;
	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	int i = 0;
	double x1, y1, z1, avgX, avgY, avgZ, maxX, maxY, maxZ, minX, minY, minZ;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}


	
	/* PUT YOUR CODE HERE */
	for(i = 0; i < lengthofavg; i++)
	{
			scanf("%lf, %lf, %lf, %d, %d, %d, %d",&x1, &y1, &z1, &bT, &bC, &bX, &bS);
			updatebuffer(x, lengthofavg, x1);
			updatebuffer(y, lengthofavg, y1);
			updatebuffer(z, lengthofavg, z1);
	}
	do
	{
		scanf("%lf, %lf, %lf, %d, %d, %d, %d",&x1, &y1, &z1, &bT, &bC, &bX, &bS);
		updatebuffer(x, lengthofavg, x1);
		updatebuffer(y, lengthofavg, y1);
		updatebuffer(z, lengthofavg, z1);
		avgX=avg(x,lengthofavg);
		avgY=avg(y,lengthofavg);
		avgZ=avg(z,lengthofavg);
		maxmin(x,lengthofavg,&maxX,&minX);
		maxmin(y,lengthofavg,&maxY,&minY);
		maxmin(z,lengthofavg,&maxZ,&minZ);
		printf("%10lf, %10lf, %10lf, %10lf, %10lf, %10lf, %10lf, %10lf, %10lf, %10lf, %10lf, %10lf\n", x1, avgX, minX, maxX, y1, avgY, minY, maxY, z1, avgZ, minZ, maxZ);
		fflush(stdout);
	}while(bS==0);
	
}


