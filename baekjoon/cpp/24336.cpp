#include <iostream>
#include <string>
#include <vector>
using namespace std;

// {{"Station name", "distance"}, {"arrival", "departure"}}
vector<pair<pair<string,double>,pair<int,int>>> station = {
    {{"Seoul", 0.0}, {0,0}},
    {{"Yeongdeungpo", 9.1}, {0,0}},
    {{"Anyang", 23.9}, {0,0}},
    {{"Suwon", 41.5}, {0,0}},
    {{"Osan", 56.5}, {0,0}},
    {{"Seojeongri", 66.5}, {0,0}},
    {{"Pyeongtaek", 75.0}, {0,0}},
    {{"Seonghwan", 84.4}, {0,0}},
    {{"Cheonan", 96.6}, {0,0}},
    {{"Sojeongni", 107.4}, {0,0}},
    {{"Jeonui", 114.9}, {0,0}},
    {{"Jochiwon", 129.3}, {0,0}},
    {{"Bugang", 139.8}, {0,0}},
    {{"Sintanjin", 151.9}, {0,0}},
    {{"Daejeon", 166.3}, {0,0}},
    {{"Okcheon", 182.5}, {0,0}},
    {{"Iwon", 190.8}, {0,0}},
    {{"Jitan", 196.4}, {0,0}},
    {{"Simcheon", 200.8}, {0,0}},
    {{"Gakgye", 204.6}, {0,0}},
    {{"Yeongdong", 211.6}, {0,0}},
    {{"Hwanggan", 226.2}, {0,0}},
    {{"Chupungnyeong", 234.7}, {0,0}},
    {{"Gimcheon", 253.8}, {0,0}},
    {{"Gumi", 276.7}, {0,0}},
    {{"Sagok", 281.3}, {0,0}},
    {{"Yangmok", 289.5}, {0,0}},
    {{"Waegwan", 296.0}, {0,0}},
    {{"Sindong", 305.9}, {0,0}},
    {{"Daegu", 323.1}, {0,0}},
    {{"Dongdaegu", 326.3}, {0,0}},
    {{"Gyeongsan", 338.6}, {0,0}},
    {{"Namseonghyeon", 353.1}, {0,0}},
    {{"Cheongdo", 361.8}, {0,0}},
    {{"Sangdong", 372.2}, {0,0}},
    {{"Miryang", 381.6}, {0,0}},
    {{"Samnangjin", 394.1}, {0,0}},
    {{"Wondong", 403.2}, {0,0}},
    {{"Mulgeum", 412.4}, {0,0}},
    {{"Hwamyeong", 421.8}, {0,0}},
    {{"Gupo", 425.2}, {0,0}},
    {{"Sasang", 430.3}, {0,0}},
    {{"Busan", 441.7}, {0,0}}
};

int N, Q;

int main() {
    string loc, ari, dpt;
    int arih, arim, dpth, dptm, prev=0, day=0;
    cin >> N >> Q;

    for (int i=0; i<N; i++)
    {
        cin >> loc >> ari >> dpt;

        for (auto &s: station)
        {
            if (s.first.first == loc)
            {
                if (ari != "-:-")
                {
                    arih = stoi(ari.substr(0,2));
                    arim = stoi(ari.substr(3,2));
                    if (arih*60 + arim < prev) day++;
                    s.second.first = (arih+day*24)*60 + arim;
                }
                if (dpt != "-:-")
                {
                    dpth = stoi(dpt.substr(0,2));
                    dptm = stoi(dpt.substr(3,2));
                    s.second.second = (dpth+day*24)*60 + dptm;
                    prev = (dpth)*60 + dptm;
                }
            }
        }
    }

    double d, dd, a, ad, ans;
    for (int i=0; i<Q; i++)
    {
        cin >> dpt >> ari;
        for (auto s: station)
        {
            if (s.first.first == dpt)
            {
                dd = s.first.second;
                d = s.second.second;
            }
            if (s.first.first == ari)
            {
                ad = s.first.second;
                a = s.second.first;
            }
        }
        cout << fixed;
        cout.precision(8);
        ans = (ad-dd)*60/(a-d);
        ans = ans<0 ? -ans : ans;
        cout << ans << endl;
    }
    return 0;
}