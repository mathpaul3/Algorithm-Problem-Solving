#include <iostream>
using namespace std;

int N, M;
char table[9][9]={0,};
long long maximum=-1;

void is_square(long long n) {
    for (int i=0; i*i<=n; i++) {
        if (i*i == n && maximum<n) {
            maximum = n;
        }
    }
}

void make_num(int i, int j, int di, int dj) {
    long long num=0;
    if (!di && !dj) return;
    for (; 0<=i && i<N && 0<=j && j<M; i+=di, j+=dj) {
        num *= 10;
        num += (int)(table[i][j]-'0');
        is_square(num);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> table[i][j];
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            for (int di=-N; di<=N; di++) {
                for (int dj=-M; dj<=M; dj++) {
                    make_num(i, j, di, dj);
                }
            }
        }
    }
    cout << maximum << '\n';
    return 0;
}