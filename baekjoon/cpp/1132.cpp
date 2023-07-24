#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, sz;
    long long sum=0;
    pair<long long,short> AtoJ[10];
    bool not_zero[10]={0,};
    string num;
    cin >> N;
    for (int i=0; i<10; i++) AtoJ[i].second = i;
    while (N--) {
        cin >> num;
        sz = num.size();
        long long digit = 1;
        for (int i=sz-1; i>=0; i--) {
            AtoJ[num[i]-'A'].first += digit;
            digit *= 10;
        }
        not_zero[num[0]-'A'] = true;
    }
    sort(AtoJ, AtoJ+10);
    bool zero_is_used = false;
    for (int i=0; i<10; i++) {
        if (!zero_is_used) {
            if (!not_zero[AtoJ[i].second]) zero_is_used = true;
            else sum += AtoJ[i].first*(i+1);
        } else sum += AtoJ[i].first*i;
    }
    cout << sum << '\n';
    return 0;
}