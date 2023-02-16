#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, cards[100]={0,}, closest=0;
    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> cards[i];
    for (int i=0; i<N-2; i++) {
        for (int j=i+1; j<N-1; j++) {
            for (int k=j+1; k<N; k++) {
                int tmp = cards[i]+cards[j]+cards[k];
                if (tmp<=M && tmp>closest) closest = tmp;
            }
        }
    }
    cout << closest << '\n';
    return 0;
}