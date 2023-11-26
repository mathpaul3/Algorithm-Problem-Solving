#include <iostream>
using namespace std;

int N, rate[100];
double dollar=100.0, mark;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cout << fixed;
    cout.precision(2);
    for (int i=0; i<N; i++) {
        cin >> rate[i];
        if (i && rate[i]<rate[i-1]) {
            mark = dollar/100.0*(double)rate[i-1];
            dollar = mark/(double)rate[i]*100;
        }
    }
    cout << dollar << '\n';
    return 0;
}