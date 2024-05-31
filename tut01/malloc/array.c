#include <stdlib.h>

int main(void) {
	// int a[5];
	// for (int i = 0; i < 5; i++) {
	// 	a[i] = 42;
	// }

    int *a = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        a[i] = 42;
    }

    free(a);
}
