#include <iostream>
using namespace std;

int main() {
    int N, numbers[10]={0,}, maximum=0;
    cin >> N;
    if (!N) { cout << "1\n"; return 0; }
    while (N) { numbers[N%10]++; N /= 10; }

    if ((numbers[6]+numbers[9]+1)/2 > maximum)
        maximum = (numbers[6]+numbers[9]+1)/2;
    for (int i=0; i<10; i++) {
        if (i==6 || i==9) continue;
        else if (numbers[i]>maximum)
            maximum = numbers[i];
    }
    cout << maximum << '\n';
    return 0;
}