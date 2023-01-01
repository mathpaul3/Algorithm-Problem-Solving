#include <stdio.h>

int main() {
	int T, x=1, y, i, a;
	char str[10]={0,};
	scanf("%d", &T);
	while(T+1-x) {
		y=0, i=0, a=1;
		scanf("%s", str);
		while(str[i]) {
			if(str[i]=='-') {
				++y;
				if(i>0&&str[i-1]=='-') --y;
				else if(i>0&&str[i-1]=='+') ++y;
			}
			++i;
		}
		printf("Case #%d: %d\n", x++, y);
	}
}
