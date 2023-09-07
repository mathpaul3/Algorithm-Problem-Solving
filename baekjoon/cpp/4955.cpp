#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, ni, di;
    pair<short,short> mv[4]={{-1,0},{0,-1},{1,0},{0,1}};
    
    while (cin >> N) {
        if (!N) break;
        
        int min_x=0, max_x=0, min_y=0, max_y=0;
        pair<int,int> square[200];
        for (int i=1; i<N; i++) {
            cin >> ni >> di;
            square[i].first = square[ni].first + mv[di].first;
            square[i].second = square[ni].second + mv[di].second;
            if (square[i].first<min_x) min_x = square[i].first;
            if (square[i].first>max_x) max_x = square[i].first;
            if (square[i].second<min_y) min_y = square[i].second;
            if (square[i].second>max_y) max_y = square[i].second;
        }
        cout << max_x-min_x+1 << ' ' << max_y-min_y+1 << '\n';
    }
    return 0;
}