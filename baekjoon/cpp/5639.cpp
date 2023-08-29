#include <iostream>
using namespace std;

class Node {
    int val;
    Node *left;
    Node *right;
public:
    Node(int v) { val=v; left=nullptr; right=nullptr; }
    void insert(int v) {
        if (v<val) {
            if (left) left->insert(v);
            else left = new Node(v);
        } else if (v>val) {
            if (right) right->insert(v);
            else right = new Node(v);
        }
    }
    void postorder() {
        if (left) left->postorder();
        if (right) right->postorder();
        cout << val << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Node *root = nullptr;
    int value;
    while (cin >> value) {
        if (!root) { root = new Node(value); continue; }
        root->insert(value);
    }
    root->postorder();
    return 0;
}