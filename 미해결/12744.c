#include <stdio.h>

int main() {
	int N, i=1, a[7][2]={0, }, cnt=0;
	char c;
	scanf("%d", &N);
	for (; i<=N; i++) {
		scanf("%d %c", a[i][0], c);
		if (c == '+') a[i][1]=1;
		else a[i][1]=0;
	}
	
}
