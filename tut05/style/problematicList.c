#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

static struct node *add(struct node *a, int data);
static void printList(struct node *node);
static void freeList(struct node *head);

int main() {
	struct node *head = NULL;
	head = add(head, 1);
	head = add(head, 2);
	head = add(head, 3);
	head = add(head, 4);
	printList(head);
	freeList(head);
	return 0;
}

// Adds a node to the end of a linked list
static struct node *add(struct node *n, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
	if (n == NULL) {
		n = newNode;
	} else {
        struct node *lastNode = n;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
	}
	return n;
}

// Prints all the nodes in a linked lists
static void printList(struct node *node) {
    while (node->next != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("%d\n", node->data);
    return;
}

// Frees a linked list by traversing through it iteratively
static void freeList(struct node *head) {
	if (head == NULL) {
	    return;
	}

	struct node *temp = head;
	while (head != NULL) {
	    temp = head;
	    head = head->next;
	    free(temp);
	}
}
