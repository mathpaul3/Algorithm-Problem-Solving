#include <stdio.h>
int n[23];

int main(){
	int N;
	int i;
	int p;
	
	scanf("%d",&N);
	
	for(i=0;N>i;i++){
		scanf("%d",&p);
		n[p]++;
	}
	
	for(i=1;24>i;i++){
		printf("%d ",n[i]);
	}
}
