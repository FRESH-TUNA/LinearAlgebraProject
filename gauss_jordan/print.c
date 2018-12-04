#include "matrix.h"
#include <stdio.h>

void print(float * augMatrix, int border) {
	int i;

	for(i = 0; i < border; i++)
		printf("%f\n", augMatrix[i]);

}
