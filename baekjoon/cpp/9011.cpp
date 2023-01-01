#include <iostream>
#include <vector>
using namespace std;

int T, n, i, flag;

int main() {
    cin >> T;
    while(T--)
    {
        cin >> n;
        vector<int> R(n), S(n);
        for (i=0; i<n; i++)
            cin >> R[i];
        
        for (i=1; i<=n; i++)
        {
            flag = 1;
            for (int j=R.size()-1; j>=0; j--)
            {
                if (R[j] == 0) {
                    S[j] = i;
                    R[j] = 1 << 16;
                    flag = 0;
                    break;
                } else R[j]--;
            }
            if (flag)
            {
                cout << "IMPOSSIBLE" << '\n';
                break;
            }
        }
        if (!flag)
        {
            for (int i=0; i<S.size(); i++)
                cout << S[i] << (i != S.size()-1 ? " " : "");
            cout << '\n';
        }
    }

    return 0;
}