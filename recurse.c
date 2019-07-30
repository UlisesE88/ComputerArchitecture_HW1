#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursion(int N){
	if (N == 0){
		return 2;
	}
	if (N == 1){
		return 5;
	}
	return 3*recursion(N-1) + 2*recursion(N-2) + 1;
}

int main(int argc, char* argv[]) {
	int N = atoi(argv[1]);
	printf("%i\n", recursion(N));
	return EXIT_SUCCESS;
}