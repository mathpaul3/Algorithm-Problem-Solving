#include <stdio.h>

int main() {
	int s, k, h;
	scanf("%d %d %d", &s, &k, &h);
	if (s+k+h>99) {
		printf("OK");
		return 0;
	}
	
	int min=100, univ=0;
	if (s<min) {
		min = s;
		univ = 1;
	}
	if (k<min) {
		min = k;
		univ = 2;
	}
	if (h<min) {
		min = h;
		univ = 3;
	}
	printf("%s", univ == 1 ? "Soongsil" : univ == 2 ? "Korea" : "Hanyang");
	return 0;
} 
