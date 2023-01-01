#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int N, n, i, cnt=0, flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    i = 2;
    while(N--)
    {
        cin >> n;

        if (n < i)
        {
            for (auto num: v)
            {
                if (num > n)
                    break;
                if (n == num)
                    cnt++;
            }
        }
        else
        {
            for (; i<=n; i++)
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
                {
                    v.push_back(i);
                    if (i == n)
                        cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}