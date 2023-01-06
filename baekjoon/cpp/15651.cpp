#include <iostream>
using namespace std;

int N, M;

void sequence(string s, int depth) {
	if (depth == M) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<s.size(); j++)
				cout << s[j] << ' ';
			cout << (char)('1'+i) << '\n';
		}
		return;
	}

	for (int i=0; i<N; i++)
		sequence(s+(char)('1'+i), depth+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	sequence("", 1);
	return 0;
}
