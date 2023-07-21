#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, package, unit, package_min=10000, unit_min=10000;
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> package >> unit;
        if (package<package_min) package_min = package;
        if (unit<unit_min) unit_min = unit;
    }
    if (package_min<=unit_min) cout << package_min*((N/6)+(N%6 ? 1 : 0));
    else {
        if (package_min>=unit_min*6) cout << unit_min*N;
        else cout << package_min*(N/6)+(unit_min*(N%6)>package_min ? package_min : unit_min*(N%6));
    }
    cout << '\n';
    return 0;
}