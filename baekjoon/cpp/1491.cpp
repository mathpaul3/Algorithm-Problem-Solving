#include <iostream>
using namespace std;

int main() {
    int M, N, direction=0;
    cin >> N >> M;

    int min_y=0, max_y=M-1, min_x=0, max_x=N-1;
    while (min_y!=max_y && min_x!=max_x) {
        if (direction==0) min_y++;
        else if (direction==1) max_x--;
        else if (direction==2) max_y--;
        else if (direction==3) min_x++;
        direction = (direction+1)%4;
    }
    if (direction==0 || direction==3)
        cout << max_x << ' ' << max_y << '\n';
    else cout << min_x << ' ' << min_y << '\n';

    return 0;
}