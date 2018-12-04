#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float matrix[MAX][MAX];
	float augMatrix[MAX];
	int border;
	int i;
	int flag = 0;
	
	input(matrix, augMatrix, &border);	

	gauss(matrix, augMatrix, border);
		
	zordan(matrix, augMatrix, border);
	
	
	for(i = 0; i < border; i++) {
		if(matrix[i][i] == 0) {
			if(augMatrix[i] == 0) {
				flag = 1;
				continue;
			}
			else {
				printf("not x\n");
				exit(0);
			}
		}
		else {
			augMatrix[i] = augMatrix[i] / matrix[i][i];
		}
	}
	
	if(flag == 1)
			printf("many x\n");

	else {
		for(i = 0; i < border; i++) {
			printf("%f\n", augMatrix[i]);
		}
	}
	return 0;
}
