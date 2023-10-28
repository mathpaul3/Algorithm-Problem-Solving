#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x, M;
    bool S[21]={0,};
    string command;
    cin >> M;
    while (M--) {
        cin >> command;
        switch (command[1]) {
            case 'd': cin >> x; S[x]=true; break;
            case 'e': cin >> x; S[x]=false; break;
            case 'h': cin >> x; cout << S[x] << '\n'; break;
            case 'o': cin >> x; S[x] = !S[x]; break;
            case 'l': for (int i=1; i<21; i++) S[i] = true; break;
            case 'm': for (int i=1; i<21; i++) S[i] = false; break;
        }
    }

    return 0;
}