#ifndef STACK

#define STACK 

struct Data {
	int dest;
	int source;	
	int multiplex;
	struct Data * next;
};

struct Stack {
	struct Data * head;
	int num;
};

#endif
