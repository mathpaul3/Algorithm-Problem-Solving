#include <stdio.h>

int main() {
    int pages, start, end, total;
    char sep;
    while (true) {
        bool print[1500]={0,};
        total = 0;

        scanf("%d", &pages);
        if (!pages) break;
        while (true) {
            scanf("%d%c", &start, &sep);
            if (sep=='\n') {
                print[start] = true;
                break;
            }
            if (sep==',') {
                print[start] = true;
                continue;
            }
            scanf("%d%c", &end, &sep);
            if (start>end) {
                if (sep=='\n') break;
                continue;
            }
            for (int i=start; i<=end; i++)
                print[i] = true;
            if (sep=='\n')
                break;
        }
        for (int i=1; i<=pages; i++)
            if (print[i]) total++;
        printf("%d\n", total);
    }
    return 0;
}