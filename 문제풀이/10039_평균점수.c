#include <stdio.h>

int main() {
	int sum=0, n;
	for (int i = 5; i > 0; i--) {
		scanf("%d", &n);
		if (n < 40) n = 40;
		sum += n;
	}
	printf("%d", sum/5);
} 
