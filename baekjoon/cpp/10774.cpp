#include <iostream>
#include <vector>
using namespace std;

int J, A, M=0;
char sz;
vector<char> jersey;

int main() {
    cin >> J >> A;
    for (int i=0; i<J; i++)
    {
        cin >> sz;
        jersey.push_back(sz);
    }

    for (int i=0; i<A; i++)
    {
        cin >> sz >> J;
        if (int(jersey[J-1]) <= int(sz))
        {
            M++;
            jersey[J-1] = 'Z';
        }
    }
    cout << M;

    return 0;
}