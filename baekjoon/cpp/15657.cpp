#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, cur[8];
vector<int> nums;

void sequence(int prev, int depth) {
	if (depth == M-1) {
		for (int i=prev; i<N; i++) {
			for (int j=0; j<M-1; j++)
				cout << nums[cur[j]] << ' ';
			cout << nums[i] << '\n';
		}
		return;
	}

	for (int i=prev; i<N; i++) {
		cur[depth] = i;
		sequence(i, depth+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;

	int num;
	for (int i=0; i<N; i++) {
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());

	sequence(0, 0);

	return 0;
}
