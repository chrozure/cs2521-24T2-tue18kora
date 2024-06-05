#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void solveHanoi(int numDisks, char *fromRod, char *toRod, char *otherRod);

int main(void) {
    solveHanoi(3, "A", "C", "B");
}

void solveHanoi(int numDisks, char *fromRod, char *toRod, char *otherRod) {

    // base case - no disks to move
    if (numDisks == 0) return;

    // move top n - 1 disks to otherRod
    solveHanoi(numDisks - 1, fromRod, otherRod, toRod);

    // move bottom disk to toRod
    printf("Move disk from rod %s to Rod %s\n", fromRod, toRod);

    // move top n - 1 disks to toRod
    solveHanoi(numDisks - 1, otherRod, toRod, fromRod);
}
