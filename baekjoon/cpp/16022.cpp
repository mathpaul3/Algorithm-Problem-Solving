#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, V[100]={0,}, dist_min=21e8;
    cin >> N;
    for (int i=0; i<N; i++) cin >> V[i];
    sort(V, V+N);
    for (int i=1; i<N-1; i++)
        if (dist_min>V[i+1]-V[i-1]) dist_min = V[i+1]-V[i-1];
    cout << dist_min/2 << '.' << (dist_min%2?5:0) << '\n';
    return 0;
}