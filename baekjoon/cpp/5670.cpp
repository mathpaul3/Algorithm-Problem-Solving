#include <iostream>
using namespace std;

struct Node {
    Node* next[26];
    int degree;
    bool is_finish;

    Node() {
        fill(next, next+26, nullptr);
        degree = 0; is_finish = false;
    }

    ~Node() {
        for (int i=0; i<26; i++)
            if (next[i]) delete next[i];
    }

    void insert(char *alpha) {
        if ((*alpha)==0) {
            is_finish = true;
            return;
        }
        if (!next[(*alpha)-'a']) {
            next[(*alpha)-'a'] = new Node();
            degree++;
        }
        next[(*alpha)-'a']->insert(alpha+1);
    }

    int search(int depth) {
        int sum=0, cnt=0;
        if (is_finish) sum += depth;
        if (degree>1 || is_finish) depth++;
        for (int i=0; i<26; i++) {
            if (cnt==degree) return sum;
            if (next[i]) {
                sum += next[i]->search(depth);
                cnt++;
            }
        }
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, sum;
    string word;
    while (cin >> N) {
        Node root;
        for (int i=0; i<N; i++) {
            cin >> word;
            root.insert(&word[0]);
        }
        sum = root.search(0+(root.degree==1));
        cout << fixed;
        cout.precision(2);
        cout << (double)sum/N << '\n';
    }

    return 0;
}