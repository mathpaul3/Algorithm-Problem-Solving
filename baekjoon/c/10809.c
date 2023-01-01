#include <stdio.h>

int main() {
	char c[100];
	int atoz[26] = {0, };
	scanf("%s", c);
	atoz[(int)c[0]-97] = -2;
	for (int i = 1; c[i]; i++) {
		atoz[(int)c[i]-97] == 0 ? atoz[(int)c[i]-97] += i : 0;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", atoz[i] == 0 ? -1 : atoz[i] == -2 ? 0 : atoz[i]);
	}
}
