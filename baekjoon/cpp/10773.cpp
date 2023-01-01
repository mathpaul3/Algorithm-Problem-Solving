#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int K, tmp, sum=0;

int main() {
    cin >> K;
    while (K--)
    {
        cin >> tmp;
        if (tmp != 0)
            s.push(tmp);
        else
            s.pop();
    }
    while(!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    cout << sum;
    return 0;
}