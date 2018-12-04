#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"
#include "stack.h"

float deter = 1.0;

int main(void) {
	float matrix[MAX][MAX] = {{1, 2, 3, 1, 2}, {2, 1, 3, 1, 3}, {3, 5, 2, 4, 2}, {2, 3, 1, 3, 1}, {3, 4, 5, 2, 1}};
	float up[MAX][MAX];
	float low[MAX][MAX];
	float temp[MAX][MAX];
	float solution[MAX];
	float augMatrix[MAX] = {-4, -4, 1, 0, -7};
	int border;
	int i, j;	
	
	input(matrix, augMatrix, &border);
	memcpy(up, matrix, sizeof(matrix));
	struct Stack * stack = malloc(sizeof(struct Stack));

	for(i = 0; i < border; i++) {
		low[i][i] = 1.0;
	}

	upTriangle(stack, up, border);
	lowTriangle(stack, low, border);

	for(i = 0; i < border; i++) {
		deter *= up[i][i];
		deter *= low[i][i];
	}


	if(deter == 0) {
		gauss(matrix, augMatrix, 5);
		zordan(matrix, augMatrix, 5);
		for(i = 0; i < border; i++) {
			if(matrix[i][i] == 0) {
				if(augMatrix[i] == 0) {
					printf("many x\n");
				}
				else {
					printf("not x\n");
				}
				exit(0);
			}
		}
	}
	else {
		cramer(stack, matrix, temp, up, low, solution, augMatrix, border);		
	
		for(i = 0; i < border; i++) {
			printf("%f\n", solution[i]);
		}
	}
	
	return 0;
}
