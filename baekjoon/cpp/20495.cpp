#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ll long long
using namespace std;

int N, i;
ll *least, *greatest, *a, *b, x, y;

void Init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    least = (ll *)malloc(sizeof(ll)*N);
    greatest = (ll *)malloc(sizeof(ll)*N);
    a = (ll *)malloc(sizeof(ll)*N);
    b = (ll *)malloc(sizeof(ll)*N);

    for (i=0; i<N; i++)
    {
        cin >> x >> y;
        a[i] = x-y;
        least[i] = x-y;
        b[i] = x+y;
        greatest[i] = x+y;
    }
    sort(least, least + N);
    sort(greatest, greatest + N);
}

int get_min_idx(int idx)
{
    int first=0, last=N-1, middle=(first+last)/2;
    while(first < last)
    {
        if (greatest[middle] >= a[idx])
        {
            last = middle;
        } else {
            first = middle + 1;
        }
        middle = (first+last) / 2;
    }
    return first;
}

int get_max_idx(int idx)
{
    int first=0, last=N-1, middle=(first+last)/2;
    
    if (least[last] <= b[idx]) return last+1;

    while(first < last)
    {
        if (least[middle] > b[idx])
        {
            last = middle;
        } else {
            first = middle + 1;
        }
        middle = (first+last) / 2;
    }

    return last;
}

int main() {
    Init();
    for (i=0; i<N; i++)
    {
        cout << get_min_idx(i)+1 << " ";
        cout << get_max_idx(i) << endl;
    }
    return 0;
}
