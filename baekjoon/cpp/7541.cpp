#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int scene, factors[3]={9,3,7};
    cin >> scene;
    for (int i=1; i<=scene; i++) {
        string number;
        int sz, question_idx, checksum=0;
        cin >> number;
        sz = number.size();
        for (int j=sz-1; j>=0; j--) {
            if ('0'<=number[j] && number[j]<='9')
                checksum += (number[j]-'0')*factors[(sz-j-1)%3];
            else question_idx = (sz-j-1);
        }
        for (int i=0; i<10; i++) {
            if (!((checksum+(i*factors[question_idx%3]))%10)) {
                number[sz-question_idx-1] = (char)(i+'0');
                break;
            }
        }
        cout << "Scenario #" << i << ":\n" << number << "\n\n";
    }
    return 0;
}