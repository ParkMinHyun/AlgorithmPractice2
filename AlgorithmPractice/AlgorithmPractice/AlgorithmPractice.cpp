#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int num[50], n, st[6], sp = 0;

void push(int a) {
	st[sp++] = a;
}

int pop() {
	return st[--sp];
}

void lotto(int cur) {
	if (sp == 6) {
		for (int i = 0; i < 6; i++) {
			cout << st[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = cur; i < n; i++) {
		push(num[i]);
		lotto(i + 1);
		pop();
	}
}

int main() {
	while (1) {
		cin >> n;

		if (!n) {
			break;
		}

		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		lotto(0);
		cout << '\n';

	}
	return 0;
}