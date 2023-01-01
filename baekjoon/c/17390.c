#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b) return -1;
	else if (*(int *)a > *(int *)b) return 1;
	return 0;
}

int main() {
	int N, Q, i, L, R, answer;
	scanf("%d %d", &N, &Q);
	
	int *A = (int *)malloc(sizeof(int)*(N+1));
	A[0] = 0;
	for (i=1; i<N+1; i++) scanf("%d ", &A[i]);
	
	qsort(A, N+1, sizeof(int), compare);
		
	for (i=1; i<N+1; i++)
		A[i] += A[i-1];
	
	for (i=0; i<Q; i++)
	{
		scanf("%d %d", &L, &R);
		printf("%d\n", A[R] - A[L-1]);
	}
	return 0;
}
