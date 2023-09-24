#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<pair<int,string> > pirates;
    string name;
    int height;
    while (cin >> name >> height)
        pirates.push_back(make_pair(height, name));
    sort(pirates.begin(), pirates.end());

    for (int i=1; i<pirates.size(); i++) {
        if (pirates[i].first - pirates[i-1].first <= 2)
            cout << pirates[i-1].second << ' ' << pirates[i++].second << '\n';
    }
    return 0;
}