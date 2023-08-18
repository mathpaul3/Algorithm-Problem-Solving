#include <iostream>
#include <set>
using namespace std;

int main() {
    int N, G;
    cin >> N;
    while (N--) {
        cin >> G;
        int student[300]={0,}, m=1;
        for (int i=0; i<G; i++)
            cin >> student[i];
        while (true) {
            set<int> s;
            bool flag = true;
            for (int i=0; i<G; i++) {
                if (s.find(student[i]%m)!=s.end())
                { flag = false; break; }
                else s.insert(student[i]%m);
            }
            if (flag) { cout << m << '\n'; break; }
            m++;
        }
    }
    return 0;
}