#include <stdio.h>
int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	
	int arr[n];
	int a;
	for(int i=0;i<n;++i) {
		scanf("%d", &a);
		arr[i] = a;
		if(arr[i]<x) printf("%d ", arr[i]);
	}
}
