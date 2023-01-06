#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int c;
    while(b != 0) {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int xs, ys, xe, ye, dx, dy;
    cin >> xs >> ys;
    cin >> xe >> ye >> dx >> dy;

    int gcd_num = gcd(dx, dy);
    dx = dx/gcd_num;
    dy = dy/gcd_num;

    double cur, next;
    while (true) {
        cur = (xs-xe)*(xs-xe) + (ys-ye)*(ys-ye);
        next = (xs-(xe+dx))*(xs-(xe+dx)) + (ys-(ye+dy))*(ys-(ye+dy));
        if (cur < next)
            break;
        xe += dx; ye += dy;
    }
    cout << xe << ' ' << ye << '\n';

    return 0;
}