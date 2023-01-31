#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string name="";
    int age, weight;
    while (true) {
        cin >> name >> age >> weight;
        if (name == "#") break;
        cout << name << ' ' << ((age>17||weight>=80)?"Senior":"Junior") << '\n';
    }
    return 0;
}