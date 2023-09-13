#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long n, rev;
    string num;
    priority_queue<long long> arr;
    cin >> n;
    while (n--) {
        bool zero = true;
        rev = 0;
        cin >> num;

        for (int i=num.size()-1; i>=0; i--) {
            if (zero && num[i]=='0')
                continue;
            zero = false;
            rev = rev*10 + (num[i]-'0');
        }
        arr.push(-rev);
    }

    while (!arr.empty()) {
        cout << -arr.top() << '\n';
        arr.pop();
    }
    return 0;
}