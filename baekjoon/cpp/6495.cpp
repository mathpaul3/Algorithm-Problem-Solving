#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,int> ballot;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int p, g;
    string party;
    double percentage;
    cin >> p >> g;
    while (p--) {
        cin >> party >> percentage;
        ballot[party] = (int)(percentage*10);
    }
    for (int i=1; i<=g; i++) {
        string party, op="+";
        int n, sum=0;
        bool correct;
        while (op=="+") {
            cin >> party >> op;
            sum += ballot[party];
        }
        cin >> n;
        n *= 10;
        if (op=="<") correct = sum < n;
        else if (op==">") correct = sum > n;
        else if (op=="<=") correct = sum <= n;
        else if (op==">=") correct = sum >= n;
        else if (op=="=") correct = sum == n;
        cout << "Guess #" << i << " was " << (correct ? "" : "in") << "correct.\n";
    }
    return 0;
}