#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    pair<string,int> price[10001];
    int U, N, P, min_person=10e5, min_price;
    string S;
    cin >> U >> N;
    while (N--) {
        cin >> S >> P;
        if (!price[P].second)
            price[P].first = S;
        price[P].second++;
    }
    for (int i=U; i>0; i--) {
        if (price[i].second && price[i].second <= min_person) {
            min_person = price[i].second;
            min_price = i;
        }
    }
    cout << price[min_price].first << ' ' << min_price << '\n';
}