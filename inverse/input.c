#include <stdio.h>
#include "matrix.h"

void input(double (*matrix)[MAX], double * augMatrix, double * constAugMat, int * degree) {
	int i, j;
	
	printf("Input degree of matrix: ");
	scanf("%d", degree);

	printf("Input matrix elements!: \n");
	for(i = 0; i < *degree; i++) {
		for(j = 0; j < *degree; j++) {
			scanf("%lf", matrix[i] + j);
		}
	}
	
	printf("Input result value of linear equation: ");
	for(i = 0; i < *degree; i++) {
		scanf("%lf", augMatrix + i);
		constAugMat[i] = augMatrix[i];
	}
}

