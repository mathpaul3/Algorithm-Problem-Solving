#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q, x, y, sel;
    long long int other_sum=0, other_max=0;
    cin >> N >> Q;
    long long int* vote = new long long int[N+1];

    while (Q--) {
        cin >> sel >> x >> y;
        if (sel == 1) {
            vote[y-1] += x;
            if (y != N+1) {
                other_sum += x;
                other_max = (other_max < vote[y-1] ? vote[y-1] : other_max);
            }
        }
        else if (sel == 2) {
            long long int jh = vote[N] + x;
            cout << ((((jh-1)*N < other_sum+y) || (jh<=other_max)) ? "NO" : "YES") << '\n';
        }
    }
    return 0;
}