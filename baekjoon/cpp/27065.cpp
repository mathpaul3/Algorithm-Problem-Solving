#include <iostream>
#include <vector>
using namespace std;

// 1 부족수 2 완전수 3 과잉수
int status[5001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    status[1] = 1;
    for (int i=2; i<5001; i++) {
        vector<int> aliquot;
        int sum = 0;
        for (int j=1; j*2<=i; j++) {
            if (!(i%j)) {
                aliquot.push_back(j);
            }
        }
        for (int j=0; j<aliquot.size(); j++) {
            sum += aliquot[j];
        }
        if (sum > i)
            status[i] = 3;
        else if (sum == i)
            status[i] = 2;
        else
            status[i] = 1;
    }
}

int main() {
    int N, n;
    cin >> N;
    init();

    while (N--) {
        cin >> n;
        if (status[n] != 3) {
            cout << "BOJ 2022\n";
            continue;
        }
        
        bool is_goodbye = true;
        for (int i=1; i*2<=n; i++) {
            if (!(n%i) && (status[i] == 3)) {
                is_goodbye = false;
                break;
            }
        }
        cout << (is_goodbye ? "Good Bye" : "BOJ 2022") << '\n';
    }

    return 0;
}