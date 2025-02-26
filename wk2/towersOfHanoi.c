#include <stdio.h>

void solveHanoi(int numDisks, char *fromRod, char *toRod, char *otherRod) {
    if (numDisks == 0) return;

    // move n-1 disks to "otherRod"
    solveHanoi(numDisks - 1, fromRod, otherRod, toRod);
    // move nth disk to toRod
    printf("Move disk from Rod %s to Rod %s\n", fromRod, toRod);
    // move n-1disks to "toRod"
    solveHanoi(numDisks - 1, otherRod, toRod, fromRod);
}

int main(void) {
    printf("Solving the Towers of Hanoi problem with 5 disks...\n");
    solveHanoi(5, "A", "C", "B");
    return 0;
}
