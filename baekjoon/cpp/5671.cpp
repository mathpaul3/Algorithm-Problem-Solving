#include <iostream>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M) {
        int tmp, cnt=0;
        for (int i=N; i<=M; i++) {
            bool number[10]={0,}, flag=true;
            tmp = i;
            while (tmp) {
                if (!number[tmp%10]) number[tmp%10] = true;
                else { flag = false; break; }
                tmp /= 10;
            }
            cnt += flag;
        }
        cout << cnt << '\n';
    }
    return 0;
}