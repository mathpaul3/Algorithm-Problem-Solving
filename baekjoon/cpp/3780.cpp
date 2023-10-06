#include <iostream>
using namespace std;

int find_centre(int I, pair<int,int> *corp) {
    if (I==corp[I].first) return I;
    else return find_centre(corp[I].first, corp);
}

pair<int,int> get_line_length(int I, pair<int,int> *corp) {
    if (I==corp[I].first) return make_pair(I, 0);
    pair<int,int> tmp = get_line_length(corp[I].first, corp);
    corp[I] = make_pair(tmp.first, corp[I].second + tmp.second);
    return corp[I];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, I, J;
        pair<int,int> corp[20001];
        char command;
        cin >> N;
        for (int i=1; i<=N; i++) corp[i] = make_pair(i, 0);
        while (cin >> command) {
            if (command=='O') break;
            if (command=='E') {
                cin >> I;
                cout << get_line_length(I, corp).second << '\n';
            } else {
                cin >> I >> J;
                int centre = find_centre(I, corp);
                corp[centre] = make_pair(J, (J<centre ? centre-J : J-centre)%1000);
            }
        }
    }
    return 0;
}