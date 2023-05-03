#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, A, B;
    vector<int> v;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A >> B;
        v.push_back(B-A);
    }

    if (v.size()%2) cout << 1 << '\n';
    else {
        sort(v.begin(), v.end());
        int mid = (v.size()-1)/2;
        cout << v[mid+1]-v[mid]+1 << '\n';
    }
    return 0;
}