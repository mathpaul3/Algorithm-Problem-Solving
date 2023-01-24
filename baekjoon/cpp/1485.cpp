#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        pair<int,int> points[4];
        for (int i=0; i<4; i++)
            cin >> points[i].first >> points[i].second;
        sort(points, points+4);
        ll distance[6]={0,}, cur=0;
        for (int i=0; i<3; i++) {
            for (int j=i+1; j<4; j++) {
                int xd = (points[i].first-points[j].first), yd = (points[i].second-points[j].second);
                distance[cur++] = (ll)xd*xd + (ll)yd*yd;
            }
        }
        sort(distance, distance+6);
        bool flag=true;
        for (int i=1; i<4; i++)
            if (distance[0] != distance[i]) {flag=false; break;}
        if (distance[4] != distance[5]) flag=false;
        cout << (int)flag << '\n';
    }
    return 0;
}