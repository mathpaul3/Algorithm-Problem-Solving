#include <iostream>
using namespace std;

int main() {
    int N, l, r;
    cin >> N;

    for (int l=0; l<10; l++) {
    for (int r=0; r<10; r++) {
        if (l==r) continue;
    for (int o=0; o<10; o++) {
        if (l==o || r==o) continue;
    for (int d=0; d<10; d++) {
        if (l==d || r==d || o==d) continue;
    for (int e=0; e<10; e++) {
        if (l==e || r==e || o==e || d==e) continue;
    for (int h=1; h<10; h++) {
        if (l==h || r==h || o==h || d==h || e==h) continue;
    for (int w=1; w<10; w++) {
        if (l==w || r==w || o==w || d==w || e==w || h==w) continue;
        int hello=h*10000+e*1000+l*100+l*10+o, world=w*10000+o*1000+r*100+l*10+d;
        if (hello + world == N) {
            cout << "  " << hello << '\n';
            cout << "+ " << world << '\n';
            cout << "-------\n";
            cout << (N/100000 ? " " : "  ") << N << '\n';
            return 0;
        }
    }
    }
    }
    }
    }
    }
    }
   cout << "No Answer\n";
    return 0;
}