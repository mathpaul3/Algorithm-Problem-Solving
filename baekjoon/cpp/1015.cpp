#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int,int> > pq;
int A[50], B[50];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
		pq.push(make_pair(-A[i], -i));
	}

	int i=0;
	while(!pq.empty()) {
		pair<int,int> top = pq.top();
		B[-top.second] = i++;
		pq.pop();
	}

	for (int i=0; i<N; i++)
		cout << B[i] << ' ';

	return 0;
}
