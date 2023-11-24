#include <iostream>
using namespace std;

int main() {
    int sum, sub;
    cin >> sum >> sub;
    if (sum-((sum+sub)/2)<0 || (sum+sub)%2) cout << -1 << '\n';
    else cout << (sum+sub)/2 << ' ' << sum-((sum+sub)/2) << '\n';
    return 0;
}