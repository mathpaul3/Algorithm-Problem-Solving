#include <iostream>
using namespace std;

int main() {
    int P, N, move, white=0, black=0;
    char board[102]={0,};
    cin >> P >> N;
    for (int i=0; i<N; i++) {
        cin >> move;
        int left=1, right=1;
        char me=(i%2 ? 'B':'W'), opponent=(i%2 ? 'W':'B');
        board[move] = me;
        while (move-left>0 && board[move-left]==opponent) left++;
        while (move+right<=P && board[move+right]==opponent) right++;
        if (board[move-left]==me)
            while (left>1) board[move-(--left)] = 0;
        if (board[move+right]==me)
            while (right>1) board[move+(--right)] = 0;
    }

    for (int i=1; i<=P; i++)
        if (board[i]) (board[i]=='W' ? white++ : black++);
    
    cout << white << ' ' << black << '\n';
    return 0;
}