#include <stdio.h>
#include "matrix.h"

void zordan(double (*ptrToFirstLine)[MAX], double (*ptrToInverse)[MAX], double * augMatrix, int border) {
	int i, j, k;

	for(i = border - 1; i >= 0; i--) {
		double (*pivot) [MAX] = ptrToFirstLine + i;
		double (*ipivot) [MAX] = ptrToInverse + i;

		for(j = i - 1; j >= 0; j--) {
			double (*temp)[MAX] = ptrToFirstLine + j;
			double (*temp2)[MAX] = ptrToInverse +j;

			if(*(*temp + i) != 0) {
				int k;
				double multiplex = (*(*temp + i)) / ((*(*pivot + i)));
				*(*temp + i) = 0.0;

				for(k = 0; k < border; k++) {
					*(*temp2 + k) = *(*temp2 + k) + *(*ipivot + k) * multiplex * (-1);
				}
				augMatrix[j] = augMatrix[j] + augMatrix[i] * multiplex * (-1);
			}	
		}
	}
}
