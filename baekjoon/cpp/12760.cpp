#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, max_score=0;
    int cards[100][100]={0,};
    pair<int,int> score[100];

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> cards[i][j];
        }
        score[i].second = -i;
        sort(cards[i], cards[i]+M);
    }
    for (int i=M-1; i>=0; i--) {
        int maximum=0;
        for (int j=0; j<N; j++) {
            if (cards[j][i] > maximum) maximum = cards[j][i];
        }
        for (int j=0; j<N; j++) {
            if (cards[j][i] == maximum) score[j].first++;
        }
    }
    sort(score, score+N);
    max_score = score[N-1].first;
    while (score[--N].first==max_score)
        cout << -score[N].second+1 << ' ';
    return 0;
}