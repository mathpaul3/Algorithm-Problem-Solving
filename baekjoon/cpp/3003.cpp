#include <iostream>
using namespace std;

int main() {
    int temp, king=1, queen=1, rook=2, bishop=2, knight=2, pawn=8;
    cin >> temp;
    cout << king-temp << " ";
    cin >> temp;
    cout << queen-temp << " ";
    cin >> temp;
    cout << rook-temp << " ";
    cin >> temp;
    cout << bishop-temp << " ";
    cin >> temp;
    cout << knight-temp << " ";
    cin >> temp;
    cout << pawn-temp << " ";
    return 0;
}