#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void) {
	 double matrix[MAX][MAX];
	 double inverseMat[MAX][MAX];
	 double augMatrix[MAX]; 
	 double constAugMat[MAX];
	 double solution[MAX];

	 int border;
	 int i;
	 int j;


	 input(matrix, augMatrix, constAugMat, &border);

	 for(i = 0; i < border; i++) {
		inverseMat[i][i] = 1.0;
	 }

	 gauss(matrix, inverseMat, augMatrix, border);
	
	 zordan(matrix, inverseMat, augMatrix, border);
		 
	 for(i = 0; i < border; i++) {
		 if(matrix[i][i] == 0) {
			if(augMatrix[i] == 0){
				printf("many x");
				exit(0);
			}
			else {
				printf("not x\n");
				exit(0);
			}
		 }
		 else {
			for(j = 0; j < border; j++) {
				inverseMat[i][j] = inverseMat[i][j] / matrix[i][i];
			}
		 }
	 }

	for(i = 0; i < border; i++) {
		double temp = 0.0;
		for(j = 0; j < border; j++) {
			temp = temp + inverseMat[i][j] * constAugMat[j];
		}
		solution[i] = temp;
	}

	for(i = 0; i < border; i++) {
		printf("%f\n", solution[i]);
	}
	
	 	
        return 0; 
}
