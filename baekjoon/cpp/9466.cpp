#include <iostream>
using namespace std;

int find_solo(int student, int *selection, bool *visited) {
    int next = selection[student];
    selection[student] = student;
    if (selection[next]==next) {
        visited[student] = true;
        if (visited[next]) return 1;
        else { visited[next]=true; return -1;}
    }
    int result = find_solo(next, selection, visited);
    if (result == -1) {
        if (visited[student]) return 0;
        else { visited[student]=true; return -1; }
    } else {visited[student]=true; return result+1;}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n, solo=0, selection[100001]={0,};
        bool visited[100001]={0,};
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> selection[i];
            if (selection[i] == i) visited[i]=true;
        }
        for (int i=1; i<=n; i++) {
            if (visited[i]) continue;
            solo += find_solo(i, selection, visited);
        }
        cout << solo << '\n';
    }
    return 0;
}