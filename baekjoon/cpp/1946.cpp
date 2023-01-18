#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
pair<int,int> score[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while(T--) {
		cin >> N;
		for (int i=0; i<N; i++)
			cin >> score[i].first >> score[i].second;
		sort(score, score+N);
		
		int worker=1, interview = score[0].second;
		for (int i=1; i<N; i++) {
			if (score[i].second < interview) {
				interview = score[i].second;
				worker++;
			}
		}
		cout << worker << '\n';
	}
	return 0;
}
