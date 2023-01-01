#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);
	

	int arr[num] = {0};
	int a;
	int min=1000000, max=-1000000;
	
	for(int i=0;i<num;++i){
		scanf("%d", &a);
		arr[i] = a;
		
		if(arr[i]<=min){
			min = arr[i];
		}
		
		if(arr[i]>=max){
			max = arr[i];
		}
	}
	
	printf("%d %d", min, max);
}
