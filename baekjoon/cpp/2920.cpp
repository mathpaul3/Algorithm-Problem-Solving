#include <stdio.h>
int main() {
	int a,u=0,d=0;
	for (int i=8;i;i--){
		scanf("%d", &a);
		a == i && !d ? 0 : d = 1;
		a == 9-i && !u ? 0 : u = 1;
	}
	printf(!u?"ascending":!d?"descending":"mixed");
}
