#include <iostream>
using namespace std;

typedef struct Point {
    int x;
    int y;
} Point;

int N, group_num=0, group_num_max=0;
int group[3000]={0,}, lines[3000]={0,};
pair<Point,Point> l[3000];

int max(int a, int b) { return a<b ? b : a; }
int min(int a, int b) { return a<b ? a : b; }

int direction(Point *p1, Point *p2, Point *p3) {
    Point a, b;
    a.x = p1->x-p3->x, a.y = p1->y-p3->y;
    b.x = p2->x-p3->x, b.y = p2->y-p3->y;
    if (a.x*b.y-a.y*b.x)
        return ((a.x*b.y-a.y*b.x)>0 ? 1 : -1);
    return 0;
}

bool collinear(Point *p1, Point *p2, Point *p3) {
    return
    min(p1->x, p2->x)<=p3->x && p3->x<=max(p1->x, p2->x) &&
    min(p1->y, p2->y)<=p3->y && p3->y<=max(p1->y, p2->y);
}

bool is_intersect(pair<Point,Point> *l1, pair<Point,Point> *l2) {
    int d1=direction(&l1->first, &l1->second, &l2->first), d2=direction(&l1->first, &l1->second, &l2->second),
    d3=direction(&l2->first, &l2->second, &l1->first), d4=direction(&l2->first, &l2->second, &l1->second);
    if (!d1 && collinear(&l1->first, &l1->second, &l2->first)) return true;
    if (!d2 && collinear(&l1->first, &l1->second, &l2->second)) return true;
    if (!d3 && collinear(&l2->first, &l2->second, &l1->first)) return true;
    if (!d4 && collinear(&l2->first, &l2->second, &l1->second)) return true;
    return (d1*d2<0 && d3*d4<0);
}

int parent(int node) {
    if (node==group[node]) return node;
    return group[node] = parent(group[node]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) {
        group[i] = i;
        cin >> l[i].first.x >> l[i].first.y >> l[i].second.x >> l[i].second.y;
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (is_intersect(&l[j], &l[i])) {
                int pi = parent(i), pj = parent(j);
                if (pi > pj) { pi^=pj; pj^=pi; pi^=pj; }
                group[pj] = pi;
            }
        }
    }

    for (int i=0; i<N; i++) {
        group[i] = parent(group[i]);
        if (group[i]==i) group_num++;
        if (++lines[group[i]]>group_num_max) group_num_max = lines[group[i]];
    }

    cout << group_num << '\n' << group_num_max << '\n';
    return 0;
}