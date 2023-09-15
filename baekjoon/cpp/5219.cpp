#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    short cases;
    cin >> cases;
    cin.ignore();

    while (cases--) {
        vector<pair<char,string> > trans;
        string str, hs, rhs;
        char lhs;
        int hs_cnt=0;
        getline(cin, str);
        stringstream ss(str);
        while (getline(ss, hs, ' ')) {
            if (++hs_cnt%2) lhs = hs[0];
            else {
                rhs = hs;
                trans.push_back(make_pair(lhs, rhs));
            }
        }

        hs_cnt /= 2;
        getline(cin, str);
        for (int i=0; i<hs_cnt; i++) {
            bool caught = false;
            for (int j=0; j<str.size(); j++) {
                if (str[j]==' ') caught = false;
                if (!caught && str[j]==trans[i].first) {
                    if (j+1<str.size()) 
                        str = str.substr(0, j) + trans[i].second + str.substr(j+1, str.size()-j-1);
                    else str = str.substr(0, j) + trans[i].second;
                    caught = true;
                }
            }
        }
        cout << "Transformed strings: " << str << '\n';
    }
    return 0;
}