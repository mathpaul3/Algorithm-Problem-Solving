#include <iostream>
using namespace std;

char number[11]={0,}, digit=1;

bool increase(char *num, int loc) {
    if (*(num+1)==0) {
        if ((*num)==9) {
            for (int i=0; i<=loc; i++)
                number[i] = i;
            digit++;
            if (digit==11) return false;
        } else (*num)++;
    } else {
        if ((*num)+1 < *(num+1)) (*num)++;
        else {
            for (int i=0; i<loc; i++)
                number[i] = i;
            return increase(num+1, loc+1);
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        if (!increase(&number[0], 1)) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i=digit-1; i>=0; i--)
        cout << (char)(number[i]+'0');
    cout << '\n';
    return 0;
}