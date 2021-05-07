#include <stdio.h>

int main() {
	int N, i, minus=0, sum=-1000;
	scanf("%d", &N);
	N*=N;
	while(N--) {
		scanf("%d", &i);
		if (i<0) sum<i ? sum=i : 1;
		else if (i>=0) {
			sum<0 ? sum=i : sum+=i;
		}
	}
	printf("%d", sum);
}
