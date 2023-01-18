#include <iostream>
#include <algorithm>
using namespace std;

int P[1000];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i=0; i<N; i++)
		cin >> P[i];

	sort(P, P+N);

	int sum=0, prev=0;
	for (int i=0; i<N; i++) {
		P[i] = P[i] + prev;
		sum += P[i];
		prev = P[i];
	}
	cout << sum << '\n';
	return 0;
}
