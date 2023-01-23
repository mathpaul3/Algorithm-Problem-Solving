#include <stdio.h>
#include <math.h>

int b[10000001] = {0, };

int chk(int n){
	for(int i=1;b[i]<=n;i++){
		if(b[i]==n){
			return 1;
		}
	}
	return 0;
}

int main(){
	int i, j;
	int a[10000001] = {0, }; 
	
	for(i=2;i<10000001;i++){
		for(j=2;i*j<50001;j++){
			a[i*j] = 1;
		}
	}
		
	for(i=2,j=1;i<10000001;i++){
		if(a[i]==0){
			b[j] = i;
			j++;
		}
	}
	
	int ins;
	scanf("%d", &ins);
	
	for(i=1;b[i]<=sqrt(ins);i++){
		if(ins%b[i]==0){
			if(chk(ins/b[i])){
				printf("%d %d",b[i],ins/b[i]);
				return 0;
			}
		}
	}
	puts("wrong number");
}
