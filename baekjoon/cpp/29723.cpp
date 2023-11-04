#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

pair<int,string> scores[10000];
set<string> subjects;
map<string,int> scores_map;
int N, M, K, sum=0, cnt=0, maximum=0, minimum=0;
string subject;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    M -= K;
    for (int i=0; i<N; i++) {
        cin >> scores[i].second >> scores[i].first;
        scores_map[scores[i].second] = scores[i].first;
    }

    while (K--) {
        cin >> subject;
        subjects.insert(subject);
        sum += scores_map[subject];
    }

    sort(scores, scores+N);
    for (int i=0; cnt<M; i++) {
        if (subjects.find(scores[i].second)!=subjects.end())
            continue;
        minimum += scores[i].first;
        cnt++;
    }
    cnt = 0;
    for (int i=N-1; cnt<M; i--) {
        if (subjects.find(scores[i].second)!=subjects.end())
            continue;
        maximum += scores[i].first;
        cnt++;
    }

    cout << sum + minimum << ' ' << sum + maximum << '\n';
    return 0;
}