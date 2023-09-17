#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string num_from, num_to;
    int base_from, base_to, trans;
    while (cin >> num_from >> base_from >> base_to) {
        trans = 0;
        num_to = "";
        for (int i=0; i<num_from.size(); i++) {
            trans *= base_from;
            trans += (num_from[i]>'9' ? num_from[i]-'A'+10 : num_from[i]-'0');
        }
        while (trans) {
            num_to += (trans%base_to>9 ? trans%base_to-10+'A' : trans%base_to+'0');
            trans /= base_to;
        }
        if (num_to.size()>7) cout << "  ERROR\n";
        else {
            for (int i=6; i>=0; i--) {
                if (num_to.size()>i) cout << num_to[i];
                else cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}