#include <iostream>
using namespace std;

typedef long long ll;

typedef struct Point {
    int x;
    int y;
} Point;

int direction(Point p1, Point p2, Point p3) {
    Point a, b;
    a.x = p1.x-p3.x, a.y = p1.y-p3.y;
    b.x = p2.x-p3.x, b.y = p2.y-p3.y;
    return ((ll)a.x*b.y-(ll)a.y*b.x)>0 ? 1 : -1;
}

bool is_intersect(Point *p) {
    return (direction(p[0], p[1], p[2])*direction(p[0], p[1], p[3])<0) &&
    (direction(p[2], p[3], p[0])*direction(p[2], p[3], p[1])<0);
}

int main() {
    Point p[4];
    for (int i=0; i<4; i++)
        cin >> p[i].x >> p[i].y;

    cout << is_intersect(p) << '\n';
    
    return 0;
}