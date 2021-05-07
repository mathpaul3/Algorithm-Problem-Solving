#include <stdio.h>
#include <string.h> 

int main() {
	char str[40] = {0, };
	char probb[40] = "문제\n";
	char rubduck[40] = "고무오리\n"; 
	char debugfin[40] = "고무오리 디버깅 끝\n";
	int prob=0; 
	while (1) {
		fgets(str,sizeof(str),stdin);
		if(!strcmp(str,probb)) ++prob;
		else if (!strcmp(str,rubduck)) {
			if (prob==0) prob += 2;
			else --prob;
		} else if (!strcmp(str, debugfin)) break;
	}
	printf("%s", prob==0?"고무오리야 사랑해":"힝구");
}
