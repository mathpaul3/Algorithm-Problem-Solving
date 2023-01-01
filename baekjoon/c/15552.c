#include <stdio.h>
int main() {
	int t, a, b;
	scanf("%d", &t);
	for(;t>0;t--){
		scanf("%d %d", &a, &b);
		printf("%d\n", a+b);
	}
} 
