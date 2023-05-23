#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, person=0, M=0, yyyy=2000, mm=1;
    int soldier[96001]={0,};
    cin >> N;
    for (int i=0; i<N; i++) {
        int YYYY, MM;
        char dash;
        cin >> YYYY >> dash >> MM;
        soldier[(YYYY-2000)*12+MM-1]++;
        cin >> YYYY >> dash >> MM;
        soldier[(YYYY-2000)*12+MM]--;
    }

    for (int i=0; i<96001; i++) {
        person += soldier[i];
        if (person>M) {
            M = person;
            yyyy = i/12+2000;
            mm = i%12+1;
        }
    }
    
    cout << yyyy << '-';
    cout.width(2);
    cout.fill('0');
    cout << mm << '\n';

    return 0;
}