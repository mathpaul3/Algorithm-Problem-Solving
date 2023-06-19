#include <iostream>
using namespace std;

bool is_leap_year(short YYYY) {
    if (YYYY%400) {
        if (!(YYYY%4) && (YYYY%100)) return true;
        return false;
    } else return true;
}

short day_cumulation(short YYYY, string Month) {
    short cum=0;
    if (Month == "January") return cum;
    cum += 31;
    if (Month == "February") return cum;
    cum += (is_leap_year(YYYY) ? 29 : 28);
    if (Month == "March") return cum;
    cum += 31;
    if (Month == "April") return cum;
    cum += 30;
    if (Month == "May") return cum;
    cum += 31;
    if (Month == "June") return cum;
    cum += 30;
    if (Month == "July") return cum;
    cum += 31;
    if (Month == "August") return cum;
    cum += 31;
    if (Month == "September") return cum;
    cum += 30;
    if (Month == "October") return cum;
    cum += 31;
    if (Month == "November") return cum;
    cum += 30;
    return cum;
}

int main() {
    int this_year_min, now_min;
    double percent;
    char comma, colon;
    string Month;
    short DD, YYYY, HH, MM;
    cin >> Month >> DD >> comma >> YYYY >> HH >> colon >> MM;
    this_year_min = (is_leap_year(YYYY) ? 366 : 365)*24*60;
    now_min = ((day_cumulation(YYYY, Month)+DD-1)*24+HH)*60 + MM;
    cout << fixed;
    cout.precision(15);
    cout << (double)now_min/this_year_min*100 << '\n';

    return 0;
}