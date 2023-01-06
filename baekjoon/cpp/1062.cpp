#include <iostream>
using namespace std;

int words[50];
int N, K, M=0;
int necessary = 0;

void make_combination(int cur, int K_cur, int alphas) {
    if (!K_cur) {
        int readable = 0;
        alphas += necessary;
        for (int i=0; i<N; i++) {
            if ((alphas & words[i]) == words[i])
                readable++;
        }
        M = (M < readable ? readable : M);
        return;
    }

    for (int i=cur; i<27-K_cur; i++) {
        if ((i != 19) && (i != 13) && (i != 8) && (i != 2) && (i != 0))
        make_combination(i+1, K_cur-1, alphas + (1 << i));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;


    necessary += (1 << ('a'-'a'));
    necessary += (1 << ('c'-'a'));
    necessary += (1 << ('i'-'a'));
    necessary += (1 << ('n'-'a'));
    necessary += (1 << ('t'-'a'));

    string s;
    for (int i=0; i<N; i++) {
        cin >> s;
        int sz = s.size();
        int word = 0;
        for (int j=0; j<sz; j++) {
            if (!(word & (1 << ((int)s[j]-(int)'a'))))
                word += (1 << ((int)s[j]-(int)'a'));
        }
        words[i] = word;
    }

    if (K<5) {
        cout << 0 << '\n';
        return 0;
    }
    
    make_combination(0, K-5, 0);
    cout << M << '\n';

    return 0;
}