#include <stdio.h> 

int main() {
	int N, T, Ti, d=0, x=0, y=0, temp=0;
	char dir[5]={0,};
	scanf("%d %d", &N, &T);
	while(N--) { 
		scanf("%d %s", &Ti, dir);
		if (d==0 || d==4) {
			d=0;
			x+=Ti-temp;
		} else if (d==1) {
			y-=Ti-temp;
		} else if (d==2) {
			x-=Ti-temp;
		} else if (d==3 || d==-1) {
			d=3;
			y+=Ti-temp;
		}
		temp=Ti;
		if (dir[0] == 'r') {
			++d;
		} else if (dir[0] == 'l') {
			--d;
		}
	}
	if (d==0 || d==4) {
		x+=T-temp;
	} else if (d==1) {
		y-=T-temp;
	} else if (d==2) {
		x-=T-temp;
	} else if (d==3 || d==-1) {
		y+=T-temp;
	}
	printf("%d %d", x, y);
}
