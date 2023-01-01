#include <stdio.h>

int main() {
	int T, N, M;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		if (N<12 || M<4) printf("-1\n");
		else printf("%d\n", 11*M+4);
	}
}
