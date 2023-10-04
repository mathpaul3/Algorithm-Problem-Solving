#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int,bool> > lecture;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, max_cnt=0, cnt=0, lecture_num, lecture_start, lecture_end;
    cin >> N;
    while (N--) {
        cin >> lecture_num >> lecture_start >> lecture_end;
        lecture.push(make_pair(-lecture_start, false));
        lecture.push(make_pair(-lecture_end, true));
    }
    while (!lecture.empty()) {
        (lecture.top().second ? cnt-- : cnt++);
        if (max_cnt<cnt) max_cnt = cnt;
        lecture.pop();
    }
    cout << max_cnt << '\n';
    return 0;
}