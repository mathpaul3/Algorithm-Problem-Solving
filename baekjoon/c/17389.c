#include <stdio.h>

int main() {
	int N, i, bonus=0, score=0;
	char S;
	scanf("%d", &N);
	scanf("%c", &S);
	for (i=1; i<N+1; i++)
	{
		scanf("%c", &S);
		if (S == 'O') {
			score += i + bonus++;
		} else if (S == 'X') {
			bonus = 0;
		}
	}
	printf("%d", score);
	return 0;
}
