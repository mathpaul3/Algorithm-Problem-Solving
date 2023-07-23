#include <iostream>
#include <algorithm>
using namespace std;

int score, sum=0, ord[5]={0,};
pair<int,int> arr[8];

int main() {
    for (int i=1; i<9; i++) {
        cin >> score;
        arr[i-1].first = score;
        arr[i-1].second = i;
    }
    sort(arr, arr+8);
    for (int i=7; i>2; i--) {
        ord[7-i] = arr[i].second;
        sum += arr[i].first;
    }
    sort(ord, ord+5);
    cout << sum << '\n';
    for (int i=0; i<5; i++)
        cout << ord[i] << ' ';
    return 0;
}