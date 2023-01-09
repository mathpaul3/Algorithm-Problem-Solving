#include <iostream>
#include <map>
using namespace std;

map<char,int> m;
struct node {
    char value;
    int left;
    int right;
};
node nodes[27];

int main() {
    int N;
    cin >> N;

    int node_cnt=1;
    for (int i=0; i<N; i++) {
        char v, l, r;
        int vidx, lidx, ridx;
        cin >> v >> l >> r;
        if (m.find(v) == m.end()) {
            m.insert({v, node_cnt});
            nodes[node_cnt++].value = v;
        }
        if (l != '.' && m.find(l) == m.end()) {
            m.insert({l, node_cnt});
            nodes[node_cnt++].value = l;
        }
        if (r != '.' && m.find(r) == m.end()) {
            m.insert({r, node_cnt++});
            nodes[node_cnt++].value = r;
        }
        
    }

    return 0;
}