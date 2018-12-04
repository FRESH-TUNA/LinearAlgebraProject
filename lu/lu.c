#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void upTriangle(struct Stack * stack, float (*ptrToLine)[MAX], int border)  {
	int i;
	int j;
	int l;
	int z;

	for(i = 0; i < border-1; i++) {
		if(ptrToLine[i][i] == 0) {
			for(z = i+1; z < border; z++) {
				if(ptrToLine[z][i] != 0) {
					for(l = 0; l < border; l++) {
						ptrToLine[i][l] = ptrToLine[i][l] + ptrToLine[z][l];
					}
					push(stack, i, z, -1);
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
				push(stack, j, i, multiplex);
			}	
		}
	}
}


void lowTriangle(struct Stack * stack, float (*ptrToLine)[MAX], int border) {
	int i;

	while((stack->num)>0) {
		int source = stack->head->source;
	        int dest = stack->head->dest;
	       	float multiplex = stack->head->multiplex;
		pop(stack);
		
		for(i = 0; i < border; i++) {
			ptrToLine[dest][i] = ptrToLine[dest][i] + ptrToLine[source][i] * multiplex;	
		}
	}
	
}


