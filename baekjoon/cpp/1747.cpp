#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_palindrome(int num) {
    string str = to_string(num);
    int sz = str.size(), half = sz/2;
    for (int i=0; i<half; i++) {
        if (str[i] != str[sz-1-i])
            return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    if (N==1 || N==2) {
        cout << 2 << '\n';
        return 0;
    }
    
    vector<int> prime;
    prime.push_back(2);
    for (int i=3; ; i+=2) {
        for (int j=0; j<prime.size(); j++) {
            if (!(i%prime[j])) break;
            if (i<(prime[j]*prime[j])) {
                prime.push_back(i);
                if (i>=N && is_palindrome(i)) {
                    cout << i << '\n';
                    return 0;
                }
                break;
            }
        }
    }
    return 0;
}