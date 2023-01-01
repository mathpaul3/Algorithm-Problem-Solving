#include <stdio.h>

int main() {
	int sum = 0;
	char s[15];
	scanf("%s", s);
	for (int i = 0; s[i]; i++) {
		if ((int)s[i] < 83) sum += ((int)s[i]+1)/3 - 19;
		else if ((int)s[i] < 90) sum += (int)s[i]/3 - 19;
		else if ((int)s[i] == 90) sum += 10;
	}
	printf("%d", sum);
//		switch(s[i]) {
//			case 'A' :
//				printf("%d", 10);
//				break;
//			default :
//				printf("%d", 1);
//	
//	
//	2 65~67
//	3 68~70
//	4 71~73
//	5 74~76
//	6 77~79
//	7 80~83
//	8 84~86
//	9 87~90
}
