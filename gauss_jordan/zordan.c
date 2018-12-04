#include <stdio.h>
#include "matrix.h"

void zordan(float (*ptrToFirstLine)[MAX], float * augMatrix, int border) {
	int i, j;

	for(i = border - 1; i >= 0; i--) {
		float (*pivot) [MAX] = ptrToFirstLine + i;

		for(j = i - 1; j >= 0; j--) {
			float (*temp)[MAX] = ptrToFirstLine + j;

			if(*(*temp + i) != 0) {
				int k;
				float multiplex = (*(*temp + i)) / ((*(*pivot + i)));
				*(*temp + i) = 0.0;
				augMatrix[j] = augMatrix[j] + augMatrix[i] * multiplex * (-1);
			}	
		}
	}
}
