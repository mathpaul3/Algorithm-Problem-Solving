#include <stdio.h>

int main() {
	int R, C, i, j, noGahee=0;
	int isP=0, Cs=1000, Ce=0, Rs=1000, Re=0;
	int Rg, Cg, Rp, Cp;
	scanf("%d %d", &R, &C);
	scanf("%d %d %d %d", &Rg, &Cg, &Rp, &Cp);
	char str[200][200] = {0, };

	for (i=0;i<R;i++) {
		for (j=0;j<=C;j++) {
			scanf("%c", &str[i][j]);
			if (str[i][j] == 'P' && !isP) {
				isP++;
				Cs=j;
				Rs=i;
				Ce=j+Cp;
				Re=i+Rp;
			}
			if (str[i][j] != 'P' && Cs<=j && j<Ce && Rs<=i && i<Re) {
				noGahee=1;
			}
		}
	}
	if (C<Ce-1 || R<Re-1) {
		noGahee=1;
	}
	printf("%d", noGahee);
}
