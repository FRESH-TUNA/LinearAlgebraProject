#include "matrix.h"
#include <string.h>

void swap(float (*ptrToLine)[MAX], float * augMatrix,  int dest, int source) {
		float temp[MAX];
		float temp2;

		memcpy(temp, ptrToLine + source, MAX);		
		memcpy(ptrToLine + source, ptrToLine + dest, MAX);
		memcpy(ptrToLine + dest, temp, MAX);

		temp2 = augMatrix[source];
		augMatrix[source] = augMatrix[dest];
		augMatrix[dest] = temp2;
}
