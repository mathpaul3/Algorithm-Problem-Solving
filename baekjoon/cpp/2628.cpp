#include <iostream>
using namespace std;

int main() {
    bool is_vertical, vertical[101]={0,}, horizontal[101]={0,};
    int width, height, div, num, w_local=1, h_local=1, w_max=0, h_max=0;
    cin >> width >> height >> div;
    while (div--) {
        cin >> is_vertical >> num;
        if (is_vertical) vertical[num] = true;
        else horizontal[num] = true;
    }
    for (int i=1; i<height; i++) {
        if (horizontal[i]) h_local= 1;
        else h_local++;
        if (h_local>h_max) h_max = h_local;
    }
    for (int i=1; i<width; i++) {
        if (vertical[i]) w_local = 1;
        else w_local++;
        if (w_local>w_max) w_max = w_local;
    }
    cout << h_max * w_max << '\n';
}