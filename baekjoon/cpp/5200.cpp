#include <iostream>
#define PI 3.1415926535
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int K;
    cin >> K;
    cout << fixed;
    cout.precision(2);
    for (int i=1; i<=K; i++) {
        double w, h, m, d, b, hi, ri;
        double patch_area=0.0, moat_area=0.0, sand_for_building=0.0, original_base_level=0.0, change=0.0;
        cin >> w >> h >> m >> d >> b;
        patch_area = (w-2*m)*(h-2*m);
        moat_area = h*w - patch_area;
        original_base_level = (moat_area*d)/(h*w);
        while (b--) {
            cin >> hi >> ri;
            sand_for_building += hi*PI*ri*ri;
        }
        change = original_base_level - (sand_for_building/(h*w));
        
        cout << "Data Set " << i << ":\n";
        cout << change << '\n';
    }
    return 0;
}