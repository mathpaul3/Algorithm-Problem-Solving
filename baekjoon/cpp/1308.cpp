#include <iostream>
using namespace std;

bool is_leap_year(int YYYY) {
    if (YYYY%400) {
        if (YYYY%100 && !(YYYY%4)) return true;
        else return false;
    } else return true;
}

int day_cumulation(int YYYY, int MM) {
    int cum=0;
    if (MM==1) return cum; cum += 31;
    if (MM==2) return cum; cum += 28 + is_leap_year(YYYY);
    if (MM==3) return cum; cum += 31;
    if (MM==4) return cum; cum += 30;
    if (MM==5) return cum; cum += 31;
    if (MM==6) return cum; cum += 30;
    if (MM==7) return cum; cum += 31;
    if (MM==8) return cum; cum += 31;
    if (MM==9) return cum; cum += 30;
    if (MM==10) return cum; cum += 31;
    if (MM==11) return cum; cum += 30;
    if (MM==12) return cum; cum += 31;
    return cum;
}

int main() {
    int d_day=0;
    int sYYYY, sMM, sDD, eYYYY, eMM, eDD;
    cin >> sYYYY >> sMM >> sDD;
    cin >> eYYYY >> eMM >> eDD;
    if ((eYYYY-sYYYY>1000) ||
        (eYYYY-sYYYY==1000 && sMM<eMM) ||
        (eYYYY-sYYYY==1000 && sMM==eMM && sDD<=eDD)
    ) { cout << "gg"; return 0; }

    if (sYYYY==eYYYY)
        d_day = day_cumulation(eYYYY, eMM)+eDD - (day_cumulation(sYYYY, sMM)+sDD);
    else {
        d_day += day_cumulation(sYYYY, 0) - (day_cumulation(sYYYY, sMM)+sDD);
        d_day += day_cumulation(eYYYY, eMM) + eDD;
        for (int YYYY=sYYYY+1; YYYY<eYYYY; YYYY++)
            d_day += day_cumulation(YYYY, 0);
    }
    cout << "D-" << d_day << '\n';
    return 0;
}