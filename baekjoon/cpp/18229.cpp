#include <stdio.h>

int main() {
	int N, M, K;
	int arr[100] = {0, };
	int num, mini = 101, minj = 101;
	bool bigger = false;

	scanf("%d %d %d", &N, &M, &K);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &num);
			if (!bigger) arr[i] += num;
//			printf("i : %d j : %d, arr[i] : %d\n", i, j, arr[i]);
			if (arr[i] >= K) {
				arr[i] = j;
				bigger = true;
			}
		}
//		printf("j : %d\n", arr[i]);
		if (arr[i] < minj && bigger) {
			mini = i;
			minj = arr[i];
		}
		bigger = false;
	}
	printf("%d %d", mini + 1, minj + 1);
}
