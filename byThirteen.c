#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void everyThirteen(int N){
	int i;
	for(i = 0; i < N; i++){
		printf("%d\n", 13*(i+1));
	}
}

int main (int argc, char** argv) {
	int N = atoi(argv[1]);
	everyThirteen(N);
	return EXIT_SUCCESS;
}