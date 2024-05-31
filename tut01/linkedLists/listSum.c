#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

int listSumWhile(struct node *n);
int listSumFor(struct node *n);
struct node *newNode(int val);

int main(void) {

    struct node *head = newNode(3);
    struct node *n2 = newNode(1);
    struct node *n3 = newNode(4);

    head->next = n2;
    n2->next = n3;

    int sumWhile = listSumWhile(head);
    printf("List sum while: %d\n", sumWhile);

    int sumFor = listSumFor(head);
    printf("List sum for: %d\n", sumFor);

    free(head);
    free(n2);
    free(n3);
}

struct node *newNode(int val) {
    struct node *n = malloc(sizeof(*n));

    n->value = val;
    n->next = NULL;

    return n;
}

int listSumWhile(struct node *n) {
    int sum = 0;

    struct node *curr = n;
    while (curr != NULL) {
        sum += curr->value;
        curr = curr->next;
    }
    return sum;
}

int listSumFor(struct node *n) {

    int sum = 0;
    for (struct node *curr; curr != NULL; curr = curr->next) {
        sum += curr->value;
    }
    return sum;
}
