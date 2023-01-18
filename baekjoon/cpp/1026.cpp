#include <iostream>
#include <algorithm>
using namespace std;

int N, A[50], B[50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i=0; i<N; i++)
		cin >> A[i];
	for (int i=0; i<N; i++)
		cin >> B[i];

	sort(A, A+N);
	sort(B, B+N);
	
	int sum = 0;
	for (int i=0; i<N; i++)
		sum += A[i] * B[N-1-i];
	
	cout << sum << '\n';
	return 0;
}
