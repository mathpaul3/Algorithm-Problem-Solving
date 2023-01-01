#include <iostream>
#include <cstring>
using namespace std;

int T, M, N, K, t, i, j;
int farm[50][50], v[50][50], mvx[4] = {1, 0, -1, 0}, mvy[4] = {0, 1, 0, -1};

void Init()
{
    int X, Y;
    memset(farm, 0, sizeof(farm));
    memset(v, 0, sizeof(v));
    cin >> M >> N >> K;

    for (i=0; i<K; i++)
    {
        cin >> X >> Y;
        farm[Y][X] = 1;
    }
}

void DFS(int x, int y)
{
    for (int i=0; i<4; i++)
    {
        int X = x+mvx[i], Y = y+mvy[i];
        if (0<=X && X<M && 0<=Y && Y<N)
        {
            if (farm[Y][X] && !v[Y][X])
            {
                v[Y][X] = 1;
                DFS(X, Y);
            }
        }
    }
}

int main() {
    int cnt;
    cin >> T;
    for (t=0; t<T; t++)
    {
        Init();
        cnt = 0;
        for (i=0; i<N; i++)
        {
            for (j=0; j<M; j++)
            {
                if (farm[i][j] && !v[i][j])
                {
                    cnt++;
                    v[i][j]++;
                    DFS(j, i);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}