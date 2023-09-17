#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    char F, S; // First, Second
    double f, s, h, e, dewpoint, humidex, temperature;
    while (cin >> F) {
        if (F=='E') break;
        cin >> f >> S >> s;
        if (F>S) {
            F ^= S; S ^= F; F ^= S;
            double tmp = f; f = s; s = tmp;
        }
        if (F=='D' && S=='H') {
            dewpoint = f;
            humidex = s;
            e = 6.11 * powl(2.718281828, 5417.7530 * ((1/273.16) - (1/(dewpoint+273.16))));
            h = 0.5555 * (e - 10.0);
            temperature = humidex - h;

        } else if (F=='D' && S=='T') {
            dewpoint = f;
            temperature = s;
            e = 6.11 * powl(2.718281828, 5417.7530 * ((1/273.16) - (1/(dewpoint+273.16))));
            h = 0.5555 * (e - 10.0);
            humidex = temperature + h;
        } else if (F=='H' && S=='T') {
            humidex = f;
            temperature = s;
            h = humidex - temperature;
            e = h/0.5555 + 10.0;
            dewpoint = 1/((1/273.16)-(logl(e/6.11)/5417.7530)) - 273.16;
        }
        cout << fixed;
        cout.precision(1);
        cout << "T " << temperature << " D " << dewpoint << " H " << humidex << '\n';
        
    }
    return 0;
}