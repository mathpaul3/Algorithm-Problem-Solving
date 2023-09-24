#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    pair<char,char> PLU[3] = {{'P', 'p'}, {'L', 'l'}, {'U', 'u'}};
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        int cur_plu=0, cnt=0;
        string str;
        getline(cin, str);
        for (int i=0; i<str.size(); i++) {
            if (str[i]==PLU[cur_plu].first || str[i]==PLU[cur_plu].second) {
                if (cur_plu==2) cnt++;
                cur_plu = (cur_plu+1)%3;
            }

        }
        cout << cnt << '\n';
    }
    return 0;
}