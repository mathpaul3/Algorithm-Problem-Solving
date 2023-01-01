#include <iostream>
using namespace std;

int a, b, r, gcd, x, y, lcm;

int main() {
    cin >> a >> b;

    a > b ? 1 : (r=a,a=b,b=r);
    x=a, y=b;

    while(b)
    {
        r = a%b;
        a = b;
        b = r;
    }
    gcd = a;
    lcm = x*y / gcd;
    cout << gcd << '\n' << lcm;

    return 0;
}