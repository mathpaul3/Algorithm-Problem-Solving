#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    double H, U, D, F, cur, climb, fatigue, day;
    while (cin >> H >> U >> D >> F) {
        if (!H) break;
        cur=0; climb=0; fatigue=0; day=0;
        while (0<=cur) {
            day++;
            climb = U - fatigue;
            if (climb<0) climb = 0;
            if (H < (cur += climb)) break;
            cur -= D;
            if (cur < 0) break;
            fatigue += U*F/100;
        }
        if (cur>H) cout << "success on day " << day << '\n';
        else cout << "failure on day " << day << '\n';
    }
    return 0;
}