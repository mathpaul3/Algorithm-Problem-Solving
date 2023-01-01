#include <iostream>
#include <vector>
using namespace std;

int N, K, M=0, tmp;
vector<int> lan;

int sum(int div)
{
    tmp = 0;
    for (auto l: lan)
        tmp += l / div;
    
    return tmp;
}

int binary_search(int i, int N)
{
    long long left=1, right=i, mid;
    int max=1, s;

    while(right>=left)
    {
        mid = (left+right)/2;
        s = sum(mid);

        if (s>=N)
        {
            if (max < mid)
                max = mid;
            left = mid+1;
        }
        else if (s<N)
            right = mid-1;    
    }
    return max;
}

int main() {
    cin >> K >> N;
    while(K--)
    {
        cin >> tmp;
        lan.push_back(tmp);
        if (M < tmp)
            M = tmp;
    }

    cout << binary_search(M, N);
    return 0;
}