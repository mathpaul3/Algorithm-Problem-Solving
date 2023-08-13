#include <iostream>
using namespace std;

int main() {
    string s1, s2, s3;
    long long num;
    cin >> s1 >> s2 >> s3;
    if ('0'<=s1[0] && s1[0]<='9')
        num = stol(s1) + 3;
    else if ('0'<=s2[0] && s2[0]<='9')
        num = stol(s2) + 2;
    else if ('0'<=s3[0] && s3[0]<='9')
        num = stol(s3) + 1;
    if (!(num%3) && !(num%5))
        cout << "FizzBuzz\n";
    else if (!(num%3))
        cout << "Fizz\n";
    else if (!(num%5))
        cout << "Buzz\n";
    else cout << num << '\n';
    return 0;
}