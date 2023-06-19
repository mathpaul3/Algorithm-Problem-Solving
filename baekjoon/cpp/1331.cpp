#include <iostream>
using namespace std;

bool visited[6][6]={0,}, valid=true;

int main() {
    char start_a, start_n, prev_a, prev_n, alpha, num;
    int diff_a, diff_n;
    cin >> start_a >> start_n;
    prev_a = start_a; prev_n = start_n;
    visited[start_a-'A'][start_n-1] = true;
    for (int i=0; i<35; i++) {
        cin >> alpha >> num;
        diff_a = prev_a>alpha ? prev_a-alpha : alpha-prev_a;
        diff_n = prev_n>num ? prev_n-num : num-prev_n;
        if ((diff_a==1 && diff_n==2) || (diff_a==2 && diff_n==1)) {
            if (visited[alpha-'A'][num-1]) valid = false;
            else visited[alpha-'A'][num-1] = true;
        } else valid = false;
        prev_a = alpha; prev_n = num;
    }
    diff_a = start_a>prev_a ? start_a-prev_a : prev_a-start_a;
    diff_n = start_n>prev_n ? start_n-prev_n : prev_n-start_n;
    if ((diff_a!=1 || diff_n!=2) && (diff_a!=2 && diff_n!=1))
        valid = false;
    cout << (valid ? "Valid" : "Invalid") << '\n';

    return 0;
}