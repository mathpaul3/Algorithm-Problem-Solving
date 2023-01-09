#include <iostream>
using namespace std;

pair<int,int> tree[26];

void preorder(int node) {
	if (!tree[node].first && !tree[node].second) {
		cout << (char)(node+'A');
		return;
	}
	cout << (char)(node+'A');
	if (tree[node].first) preorder(tree[node].first);
	if (tree[node].second) preorder(tree[node].second);
}

void inorder(int node) {
	if (!tree[node].first && !tree[node].second) {
		cout << (char)(node+'A');
		return;
	}
	if (tree[node].first) inorder(tree[node].first);
	cout << (char)(node+'A');
	if (tree[node].second) inorder(tree[node].second);
}

void postorder(int node) {
	if (!tree[node].first && !tree[node].second) {
		cout << (char)(node+'A');
		return;
	}
	if (tree[node].first) postorder(tree[node].first);
	if (tree[node].second) postorder(tree[node].second);
	cout << (char)(node+'A');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	char node, left, right;
	for (int i=0; i<N; i++) {
		cin >> node >> left >> right;
		if (left != '.') tree[(int)(node-'A')].first = (int)(left-'A');
		if (right != '.') tree[(int)(node-'A')].second = (int)(right-'A');
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
}
