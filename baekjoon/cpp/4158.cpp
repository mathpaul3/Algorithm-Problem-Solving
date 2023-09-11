#include <iostream>
#include <unordered_set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, number;
    while (cin >> N >> M) {
        int dup=0;
        if (!N && !M) break;
        unordered_set<int> CD;
        while (N--) {
            cin >> number;
            CD.insert(number);
        }
        while (M--) {
            cin >> number;
            if (CD.find(number) != CD.end()) dup++;
        }
        cout << dup << '\n';
    }
    return 0;
}