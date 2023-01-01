#include <stdio.h>
#include <stdbool.h>

int main() {
    int i, tmp;
    bool students[30] = {0,};
    for (i=0; i<28; i++) {
        scanf("%d", &tmp);
        students[tmp-1] = true;
    }
    for (i=0; i<30; i++) {
        if (!students[i])
            printf("%d\n", i+1);
    }
    return 0;
}