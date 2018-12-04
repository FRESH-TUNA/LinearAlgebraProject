#include "stack.h"
#include <stdlib.h>

void push(struct Stack * stack, int dest, int source, float multiplex) {
	if(stack->num == 0) {
	       stack->head = malloc(sizeof(struct Data));
	       stack->head->dest = dest;
	       stack->head->source = source;
	       stack->head->multiplex = multiplex;
	       stack->num++;
	}
	else {
	       struct Data * newData = malloc(sizeof(struct Data));
	       newData->next = stack->head;
	       newData->dest = dest;
	       newData->source = source;
	       newData->multiplex = multiplex;
	       stack->head = newData;
	       stack->num++;
	}
}

void pop(struct Stack * stack) {
	struct Data * remove;

	if(stack->num != 0) {
		remove = stack->head;
		stack->head = stack->head->next;
		free(remove);
		stack->num--;
	}
}
