#include <stdlib.h>

#include "Stack.h"
#include "Queue.h"

struct queue {
	Stack s1;
	Stack s2;
};

Queue QueueNew(void) {
	Queue q = malloc(sizeof(*q));
	q->s1 = StackNew();
	q->s2 = StackNew();
	return q;
}

void QueueEnqueue(Queue q, int item) {
	StackPush(q->s1, item);
}

int QueueDequeue(Queue q) {
	while (StackSize(q->s1) > 0) {
		int topItem = StackPop(q->s1);
		StackPush(q->s2, topItem);
	}

	int returnValue = StackPop(q->s2);

	while (StackSize(q->s2) > 0) {
		int topItem = StackPop(q->s2);
		StackPush(q->s1, topItem);
	}

	return returnValue;
}

void QueueFree(Queue q) {
	StackFree(q->s1);
	StackFree(q->s2);
	free(q);
}
