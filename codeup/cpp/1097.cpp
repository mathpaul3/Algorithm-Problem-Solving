#include <stdio.h>
int a[20][20];

int main(){
	int Badookpan_Now;
	int i, j;
	int n;
	int p, s;
	
	for(i=1;i<=19;i++){
		for(j=1;j<=19;j++){
			scanf("%d", &Badookpan_Now);
			a[i][j]=Badookpan_Now;
		}
	}
	
	scanf("%d", &n);
	
	for(;n>0;n--){
		scanf("%d %d", &p, &s);
		
		for(i=1;i<=19;i++){
			a[i][p] = a[i][p]==0? 1:0;
		}
		
		for(j=1;j<=19;j++){
			a[s][j] = a[s][j]==0? 1:0;
		}
//		a[s][p] = a[s][p]==0 ? 1 : 0;	
	}
	
	for(i=1;i<=19;i++){
		for(j=1;j<=19;j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
