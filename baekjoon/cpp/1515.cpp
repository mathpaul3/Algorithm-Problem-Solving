#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int sz, cnt=0, num=1, div=1;
    string s;
    cin >> s;
    sz = s.size();

    while (cnt<sz) {
        if (num/div==10 && !(num%div)) div *= 10;
        int tmp = num++, div_tmp=div;
        while (div_tmp) {
            if ((s[cnt]-'0') == tmp/div_tmp) cnt++;
            tmp %= div_tmp;
            div_tmp /= 10;
        }
    }
    cout << num-1 << '\n';

    return 0;
}