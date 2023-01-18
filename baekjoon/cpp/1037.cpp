#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, input, max=0, min=9999999;
	cin >> N;
	while (N--) {
		cin >> input;
		if (input>max) max = input;
		if (input<min) min = input;
	}
	cout << (long long)max*min << '\n';

	return 0;
}
