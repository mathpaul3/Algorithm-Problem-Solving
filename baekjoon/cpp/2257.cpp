#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    string formula;
    int sum=0;

    cin >> formula;
    for (int i=0; i<formula.size(); i++) {
        if (formula[i]=='(') {
            s.push(sum);
            sum = 0;
        }
        else if (formula[i]==')') {
            if (i+1<formula.size() && '1'<formula[i+1] && formula[i+1]<='9') {
                sum = sum*(formula[i+1]-'0') + s.top();
                s.pop(); i++;
            } else  {
                sum += s.top();
                s.pop();
            }
        } else if (i+1<formula.size() && '1'<formula[i+1] && formula[i+1]<='9'){
            sum += (formula[i]=='H' ? 1 : (formula[i]=='C' ? 12 : 16)) * (formula[i+1]-'0');
            i++;
        }
        else sum += (formula[i]=='H' ? 1 : (formula[i]=='C' ? 12 : 16));
    }

    cout << sum << '\n';
    return 0;
}