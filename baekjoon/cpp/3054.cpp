#include <iostream>
using namespace std;

bool shape[5][4]={
    {0,0,1,0},
    {0,1,0,1},
    {1,0,0,0},
    {0,1,0,1},
    {0,0,1,0},
};
string frame[5];

void decorate(char c, bool is_wendy, bool is_overlap) {
    for (int i=0; i<5; i++) {
        for (int j=0; j<4; j++) {
            if (is_overlap && i==2 && !j) {
                frame[i] += '*';
                continue;
            } 
            if (i==2 && j==2) {
                frame[i] += c;
                continue;
            }
            if (shape[i][j])
                frame[i] += (is_wendy ? '*' : '#');
            else frame[i] += '.';
        }
    }
}

int main() {
    string s;
    cin >> s;
    int sz=s.size();
    for (int i=0; i<sz; i++)
        decorate(s[i], !((i+1)%3), i&&((i+1)%3==1));

    for (int i=0; i<5; i++)
        cout << frame[i] << (i==2 ? ((sz%3 ? '#':'*')) : '.') << '\n';
    return 0;
}