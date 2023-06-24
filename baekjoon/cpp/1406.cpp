#include <iostream>
using namespace std;

struct Node {
    char alpha;
    Node* prev;
    Node* next;
    Node(char c) { alpha=c; prev=nullptr; next=nullptr; }
    ~Node() {
        if (prev) prev->next = next;
        if (next) next->prev = prev;
    }
    Node* insert_next(Node *n) {
        next = n;
        n->prev = this;
        return n;
    }
    Node* L() { return (prev ? prev : this); }
    Node* D() { return (next ? next : this); }
    Node* B() {
        delete next;
        return this;
    }
    Node* P(Node *n) {
        if (next) next->prev = n;
        n->next = next;
        n->prev = this;
        next = n;
        return n;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int M;
    char command, param;
    Node *entry, *cur;
    string s;
    cin >> s;
    entry = new Node(0);
    cur = entry;
    for (int i=0; i<s.size(); i++)
        cur = cur->insert_next(new Node(s[i]));

    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> command;
        if (command == 'L') {
            cur = cur->L();
        } else if (command == 'D') {
            cur = cur->D();
        } else if (command == 'B') {
            if (cur == entry) continue;
            cur = cur->L();
            cur = cur->B();
        } else if (command == 'P') {
            cin >> param;
            cur = cur->P(new Node(param));
        }
    }
    cur = entry->next;
    while (cur != nullptr) {
        cout << cur->alpha;
        cur = cur->next;
    }
    cout << '\n';

    return 0;
}