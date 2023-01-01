#include <iostream>
#include <string>
#include <set>
using namespace std;

int N;
string w;

struct compare {
    bool operator() (const string &a, const string &b) const {
        if (a.size() == b.size())
            return a < b;
        return a.size() < b.size();
    }
};

int main() {
    set<string, compare> word;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> w;
        word.insert(w);
    }
    
    for (auto s: word)
        cout << s << endl;

    return 0;
}