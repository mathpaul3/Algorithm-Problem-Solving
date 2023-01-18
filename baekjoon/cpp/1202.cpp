#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K, C, bag[300000] = {0, };
pair<int,int> info[300000];
priority_queue<int> V;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i=0; i<N; i++)
		cin >> info[i].first >> info[i].second;
	for (int i=0; i<K; i++)
		cin >> bag[i];
	sort(info, info+N);
	sort(bag, bag+K);

	int prev=0, cur, limit;
	long long sum=0;
	for (int i=0; i<K; i++) {
		limit = bag[i];
		cur = prev;
		while (cur<N) {
			if (limit < info[cur].first) { prev = cur; break; }
			else V.push(info[cur].second);
			cur++;
		}
		if (!V.empty()) { sum += V.top(); V.pop(); }
		if (cur >= N) prev = cur;
	}
	cout << sum << '\n';
	return 0;
}
