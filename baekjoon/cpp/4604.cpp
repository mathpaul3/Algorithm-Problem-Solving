#include <iostream>
using namespace std;

char change(char number) {
    switch(number) {
        case 0: return ' ';
        case 27: return '\'';
        case 28: return ',';
        case 29: return '-';
        case 30: return '.';
        case 31: return '?';
        default: return (char)(number-1+'A');
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s, ans;
    char chr=0, enc_cnt=0, cnt_blank=0;

    while (getline(cin, s)) {
        if (s=="*") {
            if (enc_cnt) {
                while (++enc_cnt<=5)
                    chr <<= 1;
                ans += change(chr);
            }
            cout << ans << '\n';
            chr = 0; enc_cnt=0; cnt_blank=0;
            ans = "";
        }
        if (s=="#") break;
        for (int i=0; i<s.size(); i++) {
            if (s[i]==' ') cnt_blank++;
            else {
                if (!cnt_blank) continue;
                if (enc_cnt==5) { ans += change(chr); chr = 0; enc_cnt = 0; }
                chr = (chr<<1) + (cnt_blank%2 ? 0 : 1);
                enc_cnt++;
                cnt_blank = 0;
            }
        }
    }
    return 0;
}