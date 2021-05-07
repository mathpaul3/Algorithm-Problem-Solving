#include <stdio.h>
#include <string.h>

int main() {
	int word = 0;
	char s[1000000] = {0, };
	fgets(s, sizeof(s), stdin);
	for (int i = 0; i < strlen(s) - 2; i++) {
		if (s[i] == (char)32) ++word;
	}
	if (s[0]==(char)32) --word;
	if (s[strlen(s)-1]==(char)32) --word;
	word++;
	printf("%d", word);
}
