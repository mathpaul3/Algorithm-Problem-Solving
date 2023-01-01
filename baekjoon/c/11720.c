#include <stdio.h>

int main() {
	char c;
	int N, sum=0;
	scanf("%d", &N);
	getchar();
	while (N) {
		scanf("%c", &c);
		sum += (int)c - 48;
		N--;
	}
	getchar();
	printf("%d", sum);
} 
