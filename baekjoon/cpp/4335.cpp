#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1) {
        stack<pair<int,bool> > nums;
        string too, somehow;
        int num;
        bool liar = false;
        while (cin >> num) {
            if (!num) break;
            cin >> too >> somehow;
            if (too[0]=='r') break;
            nums.push(make_pair(num, somehow[0]=='h'));
        }
        if (!num) break;
        while (!nums.empty()) {
            if (nums.top().first==num || (nums.top().first>num) ^ nums.top().second) {
                liar = true; break;
            }
            nums.pop();
        }
        if (liar) cout << "Stan is dishonest\n";
        else cout << "Stan may be honest\n";
    }
    return 0;
}