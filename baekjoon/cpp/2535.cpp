#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, country;
    bool has_same=false;
    tuple<int,int,int> student[100];
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> get<1>(student[i]) >> get<2>(student[i]) >> get<0>(student[i]);

    sort(student, student+N);
    country = get<1>(student[N-1]);
    has_same = (get<1>(student[N-1]) == get<1>(student[N-2]));
    cout << get<1>(student[N-1]) << ' ' << get<2>(student[N-1]) << '\n';
    cout << get<1>(student[N-2]) << ' ' << get<2>(student[N-2]) << '\n';
    for (int i=N-3; i>=0; i--) {
        if (has_same && get<1>(student[i])==country) continue;
        cout << get<1>(student[i]) << ' ' << get<2>(student[i]) << '\n';
        break;
    }

    return 0;
}