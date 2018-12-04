#include <stdio.h>
#include "matrix.h"

void input(float (*matrix)[MAX], float * augMatrix, int * degree) {
	int i, j;
	
	printf("Input degree of matrix: ");
	scanf("%d", degree);

	printf("Input matrix elements!: \n");
	for(i = 0; i < *degree; i++) {
		for(j = 0; j < *degree; j++) {
			scanf("%f", matrix[i] + j);
		}
	}
	
	printf("Input result value of linear equation: ");
	for(i = 0; i < *degree; i++) {
		scanf("%f", augMatrix + i);
	}
}

