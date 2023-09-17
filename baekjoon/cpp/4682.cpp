#include <iostream>
using namespace std;

int main() {
    int coefficients[9]={0,};
    while (cin >> coefficients[8]) {
        for (int i=7; i>=0; i--) cin >> coefficients[i];
        bool term_start = false;
        for (int i=8; i>=0; i--) {
            if (coefficients[i]) {
                if (term_start) {
                    cout << (coefficients[i]>0 ? " + " : " - ");
                    if (coefficients[i]!=1 && coefficients[i]!=-1)
                        cout << (coefficients[i]>0 ? coefficients[i] : -coefficients[i]);
                    if (i) {
                        if (i==1) cout << "x";
                        else cout << "x^" << i;
                    } else if (coefficients[i]==1 || coefficients[i]==-1)
                        cout << (coefficients[i]>0 ? coefficients[i] : -coefficients[i]);
                } else {
                    term_start = true;
                    if (coefficients[i]!=1 && coefficients[i]!=-1)
                        cout << coefficients[i];
                    else if (coefficients[i]==-1) cout << '-';
                    if (i) {
                        if (i==1) cout << "x";
                        else cout << "x^" << i;
                    }
                    else if (coefficients[i]==1 || coefficients[i]==-1)
                        cout << (coefficients[i]>0 ? coefficients[i] : -coefficients[i]);
                }
            }
        }
        if (!term_start) cout << coefficients[0];
        cout << '\n';
    }
    return 0;
}