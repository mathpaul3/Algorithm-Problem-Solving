#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, number;
    set<int> cards;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> number;
        cards.insert(number);
    }
    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> number;
        cout << (bool)(cards.find(number)!=cards.end()) << ' ';
    }
    return 0;
}