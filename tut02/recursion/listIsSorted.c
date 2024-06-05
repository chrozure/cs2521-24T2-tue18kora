#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void testListIsSorted(int values[], int size);
bool listIsSorted(struct node *list);

int main(int argc, char *argv[]) {
    testListIsSorted((int[]){}, 0);
    testListIsSorted((int[]){1}, 1);
    testListIsSorted((int[]){1, 2}, 2);
    testListIsSorted((int[]){1, 1}, 2);
    testListIsSorted((int[]){2, 1}, 2);
    testListIsSorted((int[]){1, 2, 3}, 3);
    testListIsSorted((int[]){2, 1, 3}, 3);
    testListIsSorted((int[]){1, 3, 2}, 3);
    testListIsSorted((int[]){1, 2, 3, 2}, 4);
    testListIsSorted((int[]){1, 2, 2, 3, 4}, 5);
    testListIsSorted((int[]){1, 2, 3, 2, 4}, 5);
}

void testListIsSorted(int values[], int size) {
    struct node *list = arrayToList(values, size);

    printf("List: ");
    listPrint(list);
    printf("\n");

    bool sorted = listIsSorted(list);
    printf("List %s sorted\n\n", sorted ? "is" : "is not");

    listFree(list);
}

bool listIsSorted(struct node *list) {
    // base case - empty list or 1 node in list
    if (list == NULL || list->next == NULL) return true;

    // base case - current value is greater than next one
    if (list->value > list->next->value) return false;

    // recursive case - next value is greater than current value
    return listIsSorted(list->next);
}
