#include <stdio.h>

int A;
int B;
int C;
int uDP = 10;
int pshare;
long long int puDP;

int realShare(int a, int b) {
	int cnt = 0;
	for(;a-b>=0;++cnt) {
		a -= b;
	}
	return cnt;
} 

long long int underDecimalPoint(int c, int d) {
	int share;
	int rest;
	long long int num = 0;
	while (uDP) {
		num*=10;
		share = realShare((c*10), d);
		rest = (c*10) - (share*d);
		c = rest;
		--uDP;
		num += share;
	}
	return num;
}

int main() {
	scanf("%d %d", &A, &B);
	pshare = realShare(A, B);
	C = A - (pshare*B);
	if (C % B) puDP = underDecimalPoint(C, B);
	printf("%d.%lld", pshare, puDP);
}
