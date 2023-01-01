#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int M, N, flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for (int i=2; i<=N; i++)
    {
        flag = 1;
        for (auto num: v)
        {
            if (num*num > i)
                break;
            if (!(i%num))
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            v.push_back(i);
        
        if (flag && i>=M)
            cout << i << '\n';
    }

    return 0;
}