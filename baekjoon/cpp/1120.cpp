#include <iostream>
using namespace std;

int diff(string A, string B) {
    int dif = 0;
    for (int i=0; i<A.size(); i++)
        if (A[i]!=B[i]) dif++;
    return dif;
}

int main() {
    int min_diff=100;
    string shrt, lng;
    cin >> shrt >> lng;
    if (shrt.size()>lng.size()) {
        string tmp;
        tmp = shrt;
        shrt = lng;
        lng = shrt;
    }
    if (shrt.size()==lng.size()) {
        cout << diff(shrt, lng) << '\n';
        return 0;
    }
    for (int i=0; i<lng.size()-shrt.size()+1; i++) {
        string str = lng.substr(0, i) + shrt + lng.substr(i+shrt.size());
        int dif = diff(str, lng);
        if (dif<min_diff) min_diff = dif;
    }
    cout << min_diff << '\n';
    return 0;
}