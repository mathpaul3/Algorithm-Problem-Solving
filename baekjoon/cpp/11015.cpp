#include <iostream>
using namespace std;

char upper(char c) {
    return (c>'Z' ? c-('a'-'A') : c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int K, n;
    cin >> K;
    for (int dataset=1; dataset<=K; dataset++) {
        string abbreviation, building[100];
        cin >> n;
        cin.ignore();
        for (int i=0; i<n; i++)
            getline(cin, building[i]);
        getline(cin, abbreviation);
        cout << "Data Set " << dataset << ":\n";
        for (int i=0; i<n; i++) {
            int cur=0;
            for (int j=0; j<building[i].size(); j++) {
                if (upper(building[i][j]) == upper(abbreviation[cur]))
                    if (++cur == abbreviation.size()) break;
            }
            if (cur==abbreviation.size()) cout << building[i] << '\n';
        }
        cout << '\n';
    }
    return 0;
}