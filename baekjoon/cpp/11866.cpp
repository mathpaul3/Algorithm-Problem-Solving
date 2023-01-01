#include <iostream>
#include <vector>
using namespace std;

vector<int> circle;
int N, K, i, p;

int main() {
    cin >> N >> K;
    for (i=1; i<=N; i++)
        circle.push_back(i);

    cout << '<';
    p=-1;
    for (i=0; i<N; i++)
    {
        p += K;
        if (p >= circle.size())
            p %= circle.size();
        cout << circle[p] << (circle.size() == 1 ? "" : ", ");
        circle.erase(circle.begin()+p);
        p--;
    }
    cout << '>';

    return 0;
}