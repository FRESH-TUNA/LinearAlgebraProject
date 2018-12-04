#include "stack.h"
#include "matrix.h"
#include <string.h>
#include <stdio.h>


void cramer(struct Stack * stack, float (*matrix)[MAX], float (*temp)[MAX], float (*up)[MAX], float (*low)[MAX], float * solution, float * augMatrix,  int border) {
	extern float deter;
	int i, j, z;
	float determinent = 1.0;

	for(i = 0; i < border; i++) {
		memcpy(temp, matrix, MAX*MAX);
		
		for(j = 0; j < border; j++) {
			temp[j][i] = augMatrix[j];
			
			for(z = 0; z < border; z++) {
				low[j][z] = 0.0;
			}
		}
	
		for(j = 0; j < border; j++) {
			for(z = 0; z < border; z++) {
				up[j][z] = temp[j][z];
			}
			low[j][j] = 1.0;
		}

		upTriangle(stack, up, border);
		
		lowTriangle(stack, low, border);

		for(j = 0; j < border; j++) {
			determinent = determinent * up[j][j] * low[j][j];
		}

		solution[i] = determinent / deter;
		determinent = 1.0;
	}
}
