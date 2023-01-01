#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int N, M;
string tmp;
set<string> unheard, unheard_unseen;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    while(N--)
    {
        cin >> tmp;
        unheard.insert(tmp);
    }
    while(M--)
    {
        cin >> tmp;
        if (unheard.find(tmp) != unheard.end())
        {
            unheard_unseen.insert(tmp);
        }
    }

    cout << unheard_unseen.size() << '\n';
    for (auto name: unheard_unseen)
        cout << name << '\n';

    return 0;
}