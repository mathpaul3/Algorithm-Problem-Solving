#include <iostream>
using namespace std;

int N, B, C, i;
int A[1000100];

int main() {

	cin >> N;
	for (i=0; i<N; i++)
		cin >> A[i];

	cin >> B >> C;

	long long int cnt = 0;
	for (i=0; i<N; i++)
	{
		A[i] -= B;
		cnt++;
		if (A[i]>0)
		{
			cnt += A[i]/C;
			if (A[i]%C != 0)
				cnt++;
		}
	}
	cout << cnt;

	return 0;
}