#include <stdio.h>

int main() {
	int T, a, b, k=1;
	scanf("%d", &T);
	while(T) {
		k=1, T--;
		scanf("%d %d", &a, &b);
		while(b--) {
			k = k*a%10;
		}
		printf("%d\n", k==0? 10 : k);
	}
}
