#include <iostream>
using namespace std;

int main() {
	int T, N, M, i, cnt;
	cin >> T;
	while(T--)
	{
		cnt = 1;
		cin >> N >> M;
		N = N < M-N ? N : M-N;
		for (i=0; i<N; i++)
			cnt = cnt * (M-i) / (i+1);
		cout << cnt << endl;
	}
	return 0;
}