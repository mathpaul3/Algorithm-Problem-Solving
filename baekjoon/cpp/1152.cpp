#include <iostream>
#include <string>
using namespace std;

int main() {
    bool word=false;
    int i, cnt=0;
    string s;
    getline(cin, s);

    for (i=0; i<s.length(); i++)
    {
        if(!word && s[i] != ' ')
        {
            word = true;
            cnt++;
        }
        if (s[i] == ' ')
            word = false;
    }
    cout << cnt << endl;
    return 0;
}