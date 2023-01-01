#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    int min, sec;
    cin >> a >> b >> c >> d;
    sec = a + b + c + d;
    min = (int)(sec / 60);
    sec -= min * 60;
    cout << min << endl
         << sec << endl;
}