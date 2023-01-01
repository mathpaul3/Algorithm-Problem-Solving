#include <iostream>
#include <stack>
using namespace std;

stack<pair<int,int> > s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, Ai;
    cin >> N;

    int *A = new int[N];
    for (int i=0; i<N; i++) {
        cin >> Ai;
        while (!s.empty() && (s.top().first < Ai)) {
            A[s.top().second] = Ai;
            s.pop();
        }
        s.push(make_pair(Ai, i));
    }
    while (!s.empty()) {
        A[s.top().second] = -1;
        s.pop();
    }

    for (int i=0; i<N; i++)
        cout << A[i] << " ";
    
    delete []A;
    return 0;
}