#include <iostream>
using namespace std;

string pattern;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> pattern;
	for (int i=1; i<N; i++) {
		string filename;
		cin >> filename;
		int sz=filename.size();
		for (int i=0; i<sz; i++) {
			if (pattern[i] == '?') continue;
			if (pattern[i] != filename[i]) pattern[i] = '?';
		}
	}
	cout << pattern << '\n';
	return 0;
}
