#include <iostream>
using namespace std;

int N, sz, curi=0, curj=0;
string command;
char board[10][10]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            board[i][j] = '.';
    
    cin >> command;
    sz = command.size();
    for (int i=0; i<sz; i++) {
        switch (command[i]) {
            case 'U': {
                if (curi==0) break;
                if (board[curi][curj]=='.')
                    board[curi][curj] = '|';
                else if (board[curi][curj]=='-')
                    board[curi][curj] = '+';
                curi--;
                if (board[curi][curj]=='.')
                    board[curi][curj] = '|';
                else if (board[curi][curj]=='-')
                    board[curi][curj] = '+';
                break;
            }
            case 'D': {
                if (curi==N-1) break;
                if (board[curi][curj]=='.')
                    board[curi][curj] = '|';
                else if (board[curi][curj]=='-')
                    board[curi][curj] = '+';
                curi++;
                if (board[curi][curj]=='.')
                    board[curi][curj] = '|';
                else if (board[curi][curj]=='-')
                    board[curi][curj] = '+';
                break;
            }
            case 'L': {
                if (curj==0) break;
                if (board[curi][curj]=='.')
                    board[curi][curj] = '-';
                else if (board[curi][curj]=='|')
                    board[curi][curj] = '+';
                curj--;
                if (board[curi][curj]=='.')
                    board[curi][curj] = '-';
                else if (board[curi][curj]=='|')
                    board[curi][curj] = '+';
                break;
            }
            case 'R': {
                if (curj==N-1) break;
                if (board[curi][curj]=='.')
                    board[curi][curj] = '-';
                else if (board[curi][curj]=='|')
                    board[curi][curj] = '+';
                curj++;
                if (board[curi][curj]=='.')
                    board[curi][curj] = '-';
                else if (board[curi][curj]=='|')
                    board[curi][curj] = '+';
                break;
            }
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cout << board[i][j];
        cout << '\n';
    }
    return 0;
}