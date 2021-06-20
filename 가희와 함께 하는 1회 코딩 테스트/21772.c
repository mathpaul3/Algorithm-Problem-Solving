#include <stdio.h>

int sweet_potato(char[200][200], int, int, int, int, int, int);
int max(int, int, int, int);

int main()
{
    int R, C, T, i, j, Gi, Gj;
    char str[200][200] = {
        0,
    };
    scanf("%d %d %d", &R, &C, &T);
    for (i = 0; i <= R; i++)
    {
        for (j = 0; j < C; j++)
        {
            scanf("%c", &str[i][j]);
            if (str[i][j] == 'G')
            {
                Gi = i;
                Gj = j;
            }
        }
    }

    printf("%d %d %d\n", Gi, Gj, T);
    printf("%d\n", sweet_potato(str, R, C, Gi, Gj, T, 0));
    printf("%d", (int)'G');
}

// int sweet_potato(char (*p_str)[200], int R, int C, int i, int j, int T, int sum)
// {
//     if (i < 0 || i > R || j < 0 || j >= C || p_str[i][j]=='#')
//     {

//     }
// };

int sweet_potato(char (*p_str)[200], int R, int C, int i, int j, int T, int sum)
{
    if (i < 0 || i > R || j < 0 || j >= C || p_str[i][j] == '#')
    {
        printf("no\n");
        return 0;
    }

    if (T == 0)
    {
        printf("T=0\n");
        return p_str[i][j] == 'S' ? 1 : 0;
    }

    if (p_str[i][j] == 'S')
    {
        printf("S\n");
        sum++;
    }

    int u = sweet_potato(p_str, R, C, --i, j, --T, sum);
    int d = sweet_potato(p_str, R, C, ++i, j, --T, sum);
    int l = sweet_potato(p_str, R, C, i, --j, --T, sum);
    int r = sweet_potato(p_str, R, C, i, j++, --T, sum);
    sum += max(u, d, l, r);
    printf("sum:%d max:%d", sum, max(u, d, l, r));
    return max(u, d, l, r);
};

int max(int a, int b, int c, int d)
{
    return a > b   ? a > c   ? a > d ? a : d
                     : c > d ? c
                             : d
           : b > c ? b > d ? b : d
           : c > d ? c
                   : d;
}
