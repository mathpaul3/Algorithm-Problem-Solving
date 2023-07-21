#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, maximum=0;
    string s, best_seller="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    unordered_map<string,int> books;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> s;
        books[s]++;
    }
    for (auto it=books.begin(); it!=books.end(); it++) {
        if ((*it).second>=maximum) {
            if ((*it).second==maximum) {
                if ((*it).first<best_seller) {
                    maximum = (*it).second;
                    best_seller = (*it).first;
                }
            } else {
                maximum = (*it).second;
                best_seller = (*it).first;
            }
        }
    }
    cout << best_seller << '\n';
    return 0;
}