//Nanoscale Tutorial 1. question 1 - date 05/10/2020

#include <stdio.h>
#include <math.h>

float qdot(float rad) //function to calculate for quantum dot
{
	float r1; //stores the ratio in r1

	/* We know for a sphere like quantum dot ,
	 volume = 4/3 * pi * r^3
	 surface area = 4 * pi * r^2
	 hence surface to volume ratio or R = (4pi r^2)/(4/3 pi r^3) ~ 3/r
	*/

	r1 = 3/rad;
	return r1;
}

float qwire(float len, float dia) //function to calculate for quantum wire
{
	float r2; //stores the ratio in r2

	/* We know for planar structures like quantum wire,
	 volume = pi * r^2 * l
	 surface area = 2 * pi * r * l
	 hence surface to volume ratio or R = (2pi rl)/(pi r^2 l) ~ 2/r
	 */

	 r2 = 2/(dia / 2);
	 return r2;
}

int main() //main calling function
{
	FILE *fqdot; //creating data file for quantum dot
	fqdot = fopen("qdot.txt", "w"); //opening in write mode

	printf("values for quantum dot \n");
	printf("# radius \t R \n");
	fprintf (fqdot, "# radius \t R \n");
	for (float i = 2.0; i <= 20.0; i++)
	{
		printf("%f \t %f \n", i, qdot(i)); //displaying the values
		fprintf(fqdot, "%f \t %f \n", i, qdot(i)); //storign in data file
	}
	fclose(fqdot); //closing data file

	FILE *fqwire;
	fqwire = fopen("qwire.txt", "w"); // opening a file to write the data for quantum wire

	printf("values for quantum wire \n");
	printf("# diameter \t R \n");
	fprintf (fqwire, "# diameter \t R \n");
	for (float j = 4.0; j <= 40.0; j++)
	{
		printf("%f \t %f \n", j/2, qwire(100.0, j)); //displaying the values
		fprintf(fqwire, "%f \t %f \n", j/2, qwire(100.0, j)); //storign in data file
	}
	fclose(fqwire); //closing data file

}
