#include <stdio.h>
int main() {
	int A, B, C, i=10;
	int arr[10]= {0,};
	scanf("%d %d %d", &A, &B, &C);
	C *= A*B;
	while(i) {
		i--;
		arr[C%10]++;
		C = (C-C%10)/10;
		if(C==0) break;
	}
	for (int i=0;i<10;i++) {
		printf("%d\n",arr[i]);
	}
}
