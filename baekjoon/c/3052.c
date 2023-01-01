#include <stdio.h>

int main() {
	int arr[42] = {0, }, A, N = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &A);
		arr[A%42]++;
	}
	for (int i = 0; i < 42; i++) {
		arr[i] == 0 ? 0 : N++;
	}
	printf("%d", N); 
}
