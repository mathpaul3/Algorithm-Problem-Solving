#include <iostream>
#include <algorithm>
using namespace std;

long long day;
int N, t[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> t[i];
    sort(t, t+N);

    for (int i=N-1; i>=0; i--)
        if (N-i + t[i] > day) day = N-i + t[i];
    cout << day+1 << '\n';
    return 0;
}