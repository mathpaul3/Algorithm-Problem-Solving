#include <stdio.h>

int main() {
	int arr[26] = {0, };
	int M = 0, m;
	char s[1000000];
	bool dup = false;
	scanf("%s", s);
	for (int i = 0; s[i]; i++) {
		s[i] > 95 ? ++arr[(int)s[i] - 97] : ++arr[(int)s[i] - 65];
	}
	for (int i = 0; i < 26; i++) {
		if (M < arr[i]) {
			M = arr[i];
			m = i;
			dup = false;
		} else if (arr[i] == M) dup = true;
	}
	printf("%c", dup ? '?' : (char)m+65);
}
