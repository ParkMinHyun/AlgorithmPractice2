#include "stdafx.h"
#include <iostream>
#include <map>
#include <utility>

using namespace std;

map<char, pair<char, char>> tree;

void preorder(char root) {
	if (root == '.')
		return;

	cout << root;
	preorder(tree[root].first);
	preorder(tree[root].second);
}

void inorder(char root) {
	if (root == '.')
		return;

	inorder(tree[root].first);
	cout << root;
	inorder(tree[root].second);
}


void postorder(char root) {
	if (root == '.')
		return;

	postorder(tree[root].first);
	postorder(tree[root].second);
	cout << root;
}


int main() {

	int N;
	char iA, iB, iC;

	cin >> N;
	while (N--) {
		cin >> iA >> iB >> iC;
		tree[iA] = make_pair(iB, iC);
	}

	preorder('A');
	cout << "\n";

	inorder('A');
	cout << "\n";

	postorder('A');
	cout << "\n";

	return 0;
}