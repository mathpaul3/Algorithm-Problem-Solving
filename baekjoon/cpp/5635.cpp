#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    int n;
    tuple<int,int,int,string> student[100];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> get<3>(student[i]) >> get<2>(student[i]) >> get<1>(student[i]) >> get<0>(student[i]);
    sort(student, student+n);
    cout << get<3>(student[n-1]) << '\n';
    cout << get<3>(student[0]) << '\n';
    return 0;
}