#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> person;
int N, w, h, r;

int main() {
    cin >> N;
    while(N--)
    {
        cin >> w >> h;
        person.push_back({w, h});
    }
    for (auto p: person)
    {
        r = 0;
        for (auto comp: person)
        {
            if (p.first < comp.first && p.second < comp.second)
                r++;
        }
        cout << r+1 << " ";
    }
    return 0;
}