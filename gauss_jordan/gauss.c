#include "matrix.h"
#include <string.h>

void gauss(float (*ptrToLine)[MAX], float * augMatrix, int border)  {
	int i;
	int j;

	for(i = 0; i < border-1; i++) {
		if(ptrToLine[i][i] == 0) {
			int z;
			
			for(z = i+1; z < border; z++) {
				if(ptrToLine[z][i] != 0) {
					swap(ptrToLine, augMatrix, i, z);
					break;
				}
			}
			
		}

		
		
		for(j = i+1; j < border; j++) {
			float (*temp)[MAX] = ptrToLine + j;

			if(*(*temp+i) != 0) {
				int k;
				float multiplex = (*(*temp + i)) / *(*(ptrToLine + i) +i);
				
				*(*temp + i) = 0.0;
				for(k = i+1;  k < border; k++) {
					 *(*temp +k) =  *(*temp+k) + *(*(ptrToLine + i) + k) * multiplex * (-1); 
				}
				augMatrix[j] = augMatrix[j] + augMatrix[i] * multiplex * (-1);
			}	
		}
	}
}
