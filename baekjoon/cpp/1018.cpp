#include <iostream>
#include <string>
using namespace std;

int N, M, ans=100, W[45][45], B[45][45];
char board[51][51];

int check(int y, int x) {
    char Wfirst='W';
    int Wcnt=0, Bcnt=0;
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (j>0) {
                Wfirst = (Wfirst=='W' ? 'B' : 'W');
            }
            // check Bfirst
            if (board[i+y][j+x] == Wfirst)
                Bcnt++;
            // check Wfirst
            else Wcnt++;
        }
    }
    return min(Wcnt, Bcnt);
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i=0; i<N-7; i++)
    {
        for (int j=0; j<M-7; j++)
        {
            ans = min(ans, check(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}