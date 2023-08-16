#include <iostream>
using namespace std;

int main() {
    bool paper[101][101]={0,};
    int n, l, d, area=0;
    cin >> n;
    while (n--) {
        cin >> l >> d;
        for (int i=0; i<10; i++)
            for (int j=0; j<10; j++)
                paper[d+i][l+j] = true;
    }
    for (int i=1; i<101; i++)
        for (int j=1; j<101; j++)
            if (paper[i][j]) area++;
   cout << area << '\n';
}