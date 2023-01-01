#include <stdio.h>

int main(){
	int T, R, j;
	char S[21];
	scanf("%d", &T);
	while (T) {
		for (int i = 0; i <21; i++) S[i] = NULL;	//S배열 -1로 초기화 
		
		scanf("%d", &R);
		scanf("%s", S);
		for (int i = 0; S[i] != NULL; i++) {		//S배열 -1 나올 때까지 돌면서 R번씩 출력 
			j = R;
			while (j) {
				printf("%c", S[i]);
				--j;
			}
			//printf(S[i] == -1 ? "Same" : "Different");
		}
		T--;
	}
}
