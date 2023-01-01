#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

long long int pillar;
int N, Y, X1, X2, i;
int coordinate[10100] = {0, };
vector<tuple<int,int,int>> platform;

void Init()
{
    cin >> N;
    for (i=0; i<N; i++)
    {
        cin >> Y >> X1 >> X2;
        platform.push_back(make_tuple(Y, X1, X2));
    }
    sort(platform.begin(), platform.end());
}

int main() {
    Init();
    for (auto p: platform)
    {
        tie(Y, X1, X2) = p;
        pillar += (Y-coordinate[X1])+(Y-coordinate[X2-1]);
        for (i=X1; i<X2; i++)
            coordinate[i] = Y;
    }
    cout << pillar;

    return 0;
}