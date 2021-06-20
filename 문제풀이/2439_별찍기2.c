#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++){
		for(int k=n; k-i>0; --k) printf(" ");
		for(int j=i; j>0 ;j--) printf("*");
		printf("\n"); 
	}
}
