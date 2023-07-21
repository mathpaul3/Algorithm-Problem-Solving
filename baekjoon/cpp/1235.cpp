#include <iostream>
#include <set>
using namespace std;

string number[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    int sz;
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> number[i];
    sz = number[0].size();
    for (int i=sz-1; i>=0; i--) {
        set<string> s;
        bool flag = true;
        for (int j=0; j<N; j++) {
            if (s.find(number[j].substr(i))==s.end())
                s.insert(number[j].substr(i));
            else {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << sz-i << '\n';
            return 0;
        }
    }
    return 0;
}