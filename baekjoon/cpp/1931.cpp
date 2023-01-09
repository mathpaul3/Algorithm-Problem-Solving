#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    priority_queue<pair<int,int> > meeting;
    int N, s, e;
    
    cin >> N;
    
    while (N--) {
        cin >> s >> e;
        meeting.push(make_pair(-e, -s));
    }

    int prev=0, meet=0;
    while (!meeting.empty()) {
        if (prev <= -meeting.top().second) {
            prev = -meeting.top().first;
            meet++;
        }
        meeting.pop();
    }
    
    cout << meet << '\n';

    return 0;
}