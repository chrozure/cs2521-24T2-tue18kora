#include <stdio.h>

int hash(char *key, int N);

int main(void) {

    int size = 10;
    printf("hash(\"hi\") = %d\n", hash("hi", size));
    printf("hash(\"hello\") = %d\n", hash("hello", size));
    printf("hash(\"z12345\") = %d\n", hash("z12345", size));

    return 0;
}

// Hash function which converts a string to an integer
int hash(char *key, int N) {
	int h = 0;
	char *c;
	for (c = key; *c != '\0'; c++) {
		h = h + *c;
	}
	return h % N;
}

/*
What are the defiencies of this function?
*/