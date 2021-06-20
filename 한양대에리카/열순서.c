#include <stdio.h>

int main() {
	long long int now = 0;
	char c[10] = {};
	scanf("%s", c);
	int i;
	for (i = 0; c[i] != '\0'; i++) {
		now *= 26;
		now += (c[i] - 'A' + 1);
	}
	printf("%d", now);
}
