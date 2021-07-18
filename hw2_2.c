#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main ()
{
	int start_day, next_day, flag; //random parameter and flag
	int sunny = 0, cloudy = 0, rainy = 0; //counter
	srand(time(NULL));
	printf("########## HW2-b ##########\n\n");
	printf("Randomly generating the sequences of weathers from the state transition function\n");
	start_day = (rand() % 3 + 1); //fisrt day : 3 types
	switch (start_day) {
	case 1:
		printf("Day1 : sunny\n");
		flag = 1;
		sunny++;
		break;
	case 2:
		printf("Day1 : cloudy\n");
		flag = 2;
		cloudy++;
		break;
	case 3:
		printf("Day1 : rainy\n");
		flag = 3;
		rainy++;
		break;
	}
	for (int i = 2; i <= 1000000; i++) { //second and later days
		next_day = (rand() % 10 + 1); //let the base be 1/10
		switch (flag) { //and follow the transition table
		case 1:
			if (next_day <= 8) {
				printf("Day%d : sunny\n", i);
				flag = 1;
				sunny++;
			} else {
				printf("Day%d : cloudy\n", i);
				flag = 2;
				cloudy++;
			}
			break;
		case 2:
			if (next_day <= 4) {
				printf("Day%d : sunny\n", i);
				flag = 1;
				sunny++;
			} else if (next_day <= 8) {
				printf("Day%d : cloudy\n", i);
				flag = 2;
				cloudy++;
			} else {
				printf("Day%d : rainy\n", i);
				flag = 3;
				rainy++;
			}
			break;
		case 3:
			if (next_day <= 2) {
				printf("Day%d : sunny\n", i);
				flag = 1;
				sunny++;
			} else if (next_day <= 8) {
				printf("Day%d : cloudy\n", i);
				flag = 2;
				cloudy++;
			} else {
				printf("Day%d : rainy\n", i);
				flag = 3;
				rainy++;
			}
			break;
		}
	}
	printf("\n########## HW2-c ##########\n\n");
	printf("The staionary distribution :\n");
	printf("sunny : %lf %%\n", (double)sunny / 10000);
	printf("cloudy : %lf %%\n", (double)cloudy / 10000);
	printf("rainy : %lf %%\n", (double)rainy / 10000);
	return 0;
}
