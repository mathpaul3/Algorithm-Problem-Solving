#include <stdio.h>

int main() {
	int N, i, n=0;
	char B[100]={0,};
	scanf("%d", &N);
	while (N--) {
		i=0;
		scanf("%s", B); 
		while (B[i++]);
		n+=--i;
	}
	printf("%d", n);
}
