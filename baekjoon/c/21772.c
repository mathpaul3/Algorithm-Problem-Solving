#include <stdio.h>
#include <stdlib.h>

int R, C, T, answer;
char **map;

void DFS(int i, int j, int curT, int cnt)
{
    if (i < 0 || i >= R || j < 0 || j >= C || map[i][j] == '#')
        return;
    if (curT == T)
    {
        if (map[i][j] == 'S')
            cnt++;
        if (answer < cnt)
            answer = cnt;
        return;
    }

    int temp = 0;
    if (map[i][j] == 'S')
    {
        temp = 1;
        map[i][j] = '.';
    }

    DFS(i + 1, j, curT + 1, cnt + temp);
    DFS(i, j + 1, curT + 1, cnt + temp);
    DFS(i - 1, j, curT + 1, cnt + temp);
    DFS(i, j - 1, curT + 1, cnt + temp);
    if (temp)
        map[i][j] = 'S';

    return;
}

int main()
{
    int Gi, Gj, i, j; // Gi, Gj 가희의 현재 위치
    scanf("%d %d %d", &R, &C, &T);

    map = (char **)malloc(sizeof(char *) * R);
    for (i = 0; i < R; i++)
        map[i] = (char *)malloc(sizeof(char) * C + 1);
    char *p = map[0];

    for (i = 0; i < R; i++)
    {
        p = map[i];
        scanf("%s", p);
        for (j = 0; j < C; j++)
        {
            if (p[j] == 'G')
            {
                Gi = i;
                Gj = j;
            }
        }
    }

    DFS(Gi, Gj, 0, 0);
    printf("%d", answer);

    for (i = 0; i < R; i++)
        free(map[i]);
    free(map);

    return 0;
}