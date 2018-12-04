#include "matrix.h"
#include <stdio.h>


void gauss(double (*ptrToLine)[MAX], double (*ptrToInverse)[MAX], double * augMatrix, int border)  {
	int i;
	int j;
	int z;
	int l;

	for(i = 0; i < border-1; i++) {
		if(ptrToLine[i][i] == 0) {
			for(z = i+1; z < border; z++) {
				if(ptrToLine[z][i] != 0) {
					for(l = 0; l < border; l++) {
						ptrToLine[i][l] = ptrToLine[i][l] + ptrToLine[z][l];
						ptrToInverse[i][l] = ptrToInverse[i][l] + ptrToInverse[z][l];
					}
					augMatrix[i] = augMatrix[i] + augMatrix[z];
					break;
				}
			}
		}
		
		for(j = i+1; j < border; j++) {
			double (*temp)[MAX] = ptrToLine + j;
			double (*temp2)[MAX] = ptrToInverse + j;

			if(*(*temp+i) != 0) {
				int k;
				double multiplex = (*(*temp + i)) / *(*(ptrToLine + i) +i);
				
				*(*temp + i) = 0.0;
				for(k = i+1;  k < border; k++) {
					 *(*temp +k) =  *(*temp+k) + *(*(ptrToLine + i) + k) * multiplex * (-1); 
				}
				for(k = 0; k < border; k++) {
					 *(*temp2 +k) =  *(*temp2+k) + *(*(ptrToInverse + i) + k) * multiplex * (-1); 
				}
				augMatrix[j] = augMatrix[j] + augMatrix[i] * multiplex * (-1);
			}	
		}
	}
}
