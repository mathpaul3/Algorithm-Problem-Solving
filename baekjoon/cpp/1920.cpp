#include <iostream>
#include <set>
using namespace std;

set<int> A;
int N, M, tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(N--)
    {
        cin >> tmp;
        A.insert(tmp);
    }
    cin >> M;
    while(M--)
    {
        cin >> tmp;
        cout << (A.find(tmp) != A.end()) << '\n';
    }
    return 0;
}