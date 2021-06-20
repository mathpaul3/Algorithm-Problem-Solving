#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	
	int a, b;
	a = n/10, b = n%10;
	int newnum = b*10 + (a+b)%10;
	int cycle = 1;
	
	while (newnum!=n) {
		a = newnum/10, b = newnum%10;
		newnum = b*10 + (a+b)%10;
		++cycle;
	}
	
	printf("%d", cycle);
}
