#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

int N, done, W[16][16], city[16][1<<16];

int DFS(int cur, int used) {
    if (used == done) return ((W[cur][0]==0) ? INF : W[cur][0]);
    if (city[cur][used] != -1) return city[cur][used];
    city[cur][used] = INF;
    for (int i=0; i<N; i++) {
        if (!W[cur][i]) continue;
        if ((used & (1 << i)) == (1 << i)) continue;
        city[cur][used] = min(city[cur][used], (DFS(i, used | (1 << i)) + W[cur][i]));
    }
    return city[cur][used];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(city, -1, sizeof(city));
    cin >> N;
    done = (1 << N) - 1;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> W[i][j];

    cout << DFS(0, 1) << '\n';
    return 0;
}