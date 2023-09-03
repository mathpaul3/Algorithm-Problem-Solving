#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    bool num[10001]={0,};
    for (int i=1; i<=10000; i++) {
        int tmp = i;
        while (tmp<=10000) {
            int ttmp = tmp;
            while (ttmp) { tmp+=ttmp%10; ttmp/=10; }
            if (tmp<10001) num[tmp] = true;
        }
    }

    for (int i=1; i<=10000; i++)
        if (!num[i]) cout << i << '\n';
    return 0;
}