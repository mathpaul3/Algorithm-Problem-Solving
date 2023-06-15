#include <iostream>
using namespace std;

typedef long long ll;
typedef struct Point {
    int x;
    int y;
} Point;

int max(int a, int b) { return a<b ? b : a; }
int min(int a, int b) { return a<b ? a : b; }

int direction(Point p1, Point p2, Point p3) {
    Point a, b;
    a.x = p1.x-p3.x, a.y = p1.y-p3.y;
    b.x = p2.x-p3.x, b.y = p2.y-p3.y;
    if ((ll)a.x*b.y-(ll)a.y*b.x)
        return (((ll)a.x*b.y-(ll)a.y*b.x)>0 ? 1 : -1);
    return 0;
}

bool collinear(Point p1, Point p2, Point p3) {
    return
    min(p1.x, p2.x)<=p3.x && p3.x<=max(p1.x, p2.x) &&
    min(p1.y, p2.y)<=p3.y && p3.y<=max(p1.y, p2.y);
}

bool is_intersect(Point *p) {
    int d1=direction(p[0], p[1], p[2]), d2=direction(p[0], p[1], p[3]),
    d3=direction(p[2], p[3], p[0]), d4=direction(p[2], p[3], p[1]);
    if (!d1 && collinear(p[0], p[1], p[2])) return true;
    if (!d2 && collinear(p[0], p[1], p[3])) return true;
    if (!d3 && collinear(p[2], p[3], p[0])) return true;
    if (!d4 && collinear(p[2], p[3], p[1])) return true;
    return (d1*d2<0 && d3*d4<0);
}

int main() {
    Point p[4];
    for (int i=0; i<4; i++)
        cin >> p[i].x >> p[i].y;
    
    cout << is_intersect(p) << '\n';
    return 0;
}