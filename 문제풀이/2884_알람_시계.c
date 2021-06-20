#include <stdio.h>
int main(){
	int h, m;
	scanf("%d %d", &h, &m);
	
	if(m<45) --h, m+=15;
	else m-=45;
	if(h==-1) h = 23;
	
	printf("%d %d", h, m);
}
