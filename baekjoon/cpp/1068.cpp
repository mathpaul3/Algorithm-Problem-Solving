#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[50];
int N, parent, root, del;

int DFS(int idx) {
    int sz=tree[idx].size(), cnt=0;
    if (idx==del) return 0;
    if (sz==1 && tree[idx][0]==del) return 1;
    for (int i=0; i<sz; i++) {
        if (tree[idx][i]==del) continue;
        if (tree[tree[idx][i]].size()) {
            cnt += DFS(tree[idx][i]);
        } else cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> parent;
        if (parent==-1) root = i;
        else tree[parent].push_back(i);
    }
    cin >> del;
    int sz = tree[root].size();
    cout << DFS(root) << '\n';
    return 0;
}