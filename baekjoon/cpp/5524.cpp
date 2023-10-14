#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    string name;
    cin >> N;
    while (N--) {
        cin >> name;
        for (int i=0; i<name.size(); i++)
            cout << (char)(name[i]>'Z' ? name[i] : name[i]+('a'-'A'));
        cout << '\n';
    }
    return 0;
}