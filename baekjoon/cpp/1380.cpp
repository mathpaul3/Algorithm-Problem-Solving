#include <iostream>
using namespace std;

string names[100];
bool retrieve[101]={0,};
int senario=0, n, cnt, stud_num, sum;
char c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (++senario) {
        cin >> n;
        if (!n) break;
        string s;
        cnt = n*2-1; sum = 0;
        cin.ignore();
        for (int i=0; i<n; i++) {
            getline(cin, s);
            names[i] = s;
        }
        
        // cout << cnt << '\n';
        while (cnt--) {
            cin >> stud_num >> c;
            if (retrieve[stud_num]) sum -= stud_num;
            else sum += stud_num;
            retrieve[stud_num] = !retrieve[stud_num];
        }
        retrieve[sum] = !retrieve[sum];
        cout << senario << ' ' << names[sum-1] << '\n';
    }
    return 0;
}