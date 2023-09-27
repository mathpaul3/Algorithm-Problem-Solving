#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str;
    char vowel[6]={'a','i','y','e','o','u'}, consonant[20]={'b','k','x','z','n','h','d','c','w','g','p','v','j','q','t','s','r','l','m','f'};
    while (getline(cin, str)) {
        for (int i=0; i<str.size(); i++) {
            switch(str[i]) {
                case 'A': case 'I': case 'Y': case 'E': case 'O': case 'U':
                    for (int j=0; j<6; j++) {
                        if (str[i]+('a'-'A')==vowel[j]) {
                            cout << (char)(vowel[(j+3)%6]-('a'-'A')); break;
                        }
                    }
                    break;
                case 'a': case 'i': case 'y': case 'e': case 'o': case 'u':
                    for (int j=0; j<6; j++) {
                        if (str[i]==vowel[j]) {
                            cout << vowel[(j+3)%6]; break;
                        }
                    }
                    break;
                case 'B': case 'K': case 'X': case 'Z': case 'N': case 'H': case 'D': case 'C': case 'W': case 'G': case 'P': case 'V': case 'J': case 'Q': case 'T': case 'S': case 'R': case 'L': case 'M': case 'F':
                    for (int j=0; j<20; j++) {
                        if (str[i]+('a'-'A')==consonant[j]) {
                            cout << (char)(consonant[(j+10)%20]-('a'-'A')); break;
                        }
                    }
                    break;
                case 'b': case 'k': case 'x': case 'z': case 'n': case 'h': case 'd': case 'c': case 'w': case 'g': case 'p': case 'v': case 'j': case 'q': case 't': case 's': case 'r': case 'l': case 'm': case 'f':
                    for (int j=0; j<20; j++) {
                        if (str[i]==consonant[j]) {
                            cout << consonant[(j+10)%20]; break;
                        }
                    }
                    break;
                default: cout << str[i];
            }
        }
        cout << '\n';
    }
    return 0;
}