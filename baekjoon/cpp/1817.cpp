#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, weight, local_sum=0, boxes=0;
    cin >> N >> M;
    while (N--) {
        cin >> weight;
        if (!local_sum) boxes++;
        if (local_sum+weight<=M)
            local_sum += weight;
        else if (local_sum+weight>M) {
            local_sum = weight;
            boxes++;
        }
    }
    cout << boxes << '\n';
    return 0;
}