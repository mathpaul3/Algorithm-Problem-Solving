#include <stdio.h>
int main() {
	int A,max = 0,maxi;
	for(int i=1;i<10;i++){
		scanf("%d",&A);
		max<A?max=A,maxi=i:A;
	}
	printf("%d %d",max,maxi);
}