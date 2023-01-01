#include <iostream>
#include <set>
#include <string>
using namespace std;

int N, M, i, ans=0;
string temp;
set<string> title;

void Init()
{
    cin >> N;
    for (i=0; i<N; i++)
    {
        cin >> temp;
        title.insert(temp);
    }

    cin >> M;
    for (i=1; i<=M; i++)
    {
        cin >> temp;
        auto it = title.find(temp);
        if (it != title.end())
        {
            title.erase(it);
            if (N/2 == title.size())
                ans=i;
        }
    }
    cout << ans;
}

int main() {
    Init();
    return 0;
}