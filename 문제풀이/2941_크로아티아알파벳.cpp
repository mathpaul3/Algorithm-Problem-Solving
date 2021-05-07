#include <stdio.h>

int main(int argc, char *argv[]) {
	char input[101] = {0, };
	int i=0, cnt=0;
	scanf("%s", input);
	
	for (; input[i]!=0; i++) {
		if (input[i] == 'c') {
			if (input[i+1] == '=' || input[i+1] == '-') continue;
		} else if (input[i] == 'd') {
			if (input[i+1] == 'z' && input[i+2] =='=') continue;
			else if (input[i+1] == '-') continue;
		} else if (input[i] == 'l' || input [i] == 'n') {
			if (input[i+1] == 'j') continue;
		} else if (input[i] == 's' || input[i] == 'z') {
			if (input[i+1] == '=') continue;
		}
		cnt++;
	}
	printf("%d", cnt);
}
