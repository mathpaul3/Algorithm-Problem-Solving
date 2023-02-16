#include <iostream>
using namespace std;

int N, M, card;
int cards[20000001]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> card;
        cards[card+10000000]++;
    }
    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> card;
        cout << cards[card+10000000] << ' ';
    }

    return 0;
}