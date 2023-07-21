#include <iostream>
#include <unordered_map>
using namespace std;

string root(string name, unordered_map<string,pair<string,int>> *network) {
    if ((*network)[name].first == name) return name;
    return (*network)[name].first = root((*network)[name].first, network);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, F;
    cin >> T;
    while (T--) {
        unordered_map<string, pair<string,int>> network;
        string a, b, tmp;
        cin >> F;
        while (F--) {
            cin >> a >> b;
            if (!network.count(a)) network[a] = make_pair(a, 1);
            if (!network.count(b)) network[b] = make_pair(b, 1);
            a = root(a, &network);
            b = root(b, &network);
            if (a==b) {
                cout << network[a].second << '\n';
                continue;
            }
            if (a>b) { tmp = a; a = b; b = tmp; }
            network[a].second += network[b].second;
            network[b].second = 0;
            network[b].first = a;
            cout << network[a].second << '\n';
        }
    }
    return 0;
}