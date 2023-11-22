#include <iostream>
#include <algorithm>
using namespace std;

int N, cry=0, rocks[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) cin >> rocks[i];
    sort(rocks, rocks+N);
    for (int i=1; i<N; i++)
        if (rocks[i-1]>=rocks[i]) cry++;
    cout << cry << '\n';
    return 0;
}