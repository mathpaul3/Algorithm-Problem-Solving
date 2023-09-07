#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    string d;
    int n;
    cin >> n >> d;
    cout << typeid(n-d.size()).name() << '\n';
    // if (n-d.size()<0) cout << "No solution\n";
    if (n<d.size()) cout << "No solution\n";
    else {
        cout << d;
        for (int i=1; d.size()+i<=n; i++) cout << '0';
        cout << '\n';
    }
    return 0;
}