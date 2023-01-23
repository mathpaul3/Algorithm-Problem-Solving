#include <stdio.h>
int n[20][20];

int main(){
	int N;
	int i;
	int p;
	int s;
	int j;
	
	scanf("%d",&N);
	
	for(i=0;N>i;i++){
		scanf("%d %d",&p, &s);
		n[s][p]++;
	}
	
	for(i=1;19>=i;i++){
		for(j=1;19>=j;j++){
			printf("%d ",n[i][j]);
		}
		printf("\n");
	}
}

