#include <stdio.h>

int main() {
	int N, j=0, sum=0;
	char c[81] = {0,};
	scanf("%d", &N);
	while (N) {
		N--;
		scanf("%s", c);
		for (int i = 0; c[i]; i++) {
			c[i] == 'O' ? ++j, sum += j : j=0;
            c[i] = 0;
		}
		printf("%d\n", sum);
		sum=0, j=0;
	}
}
