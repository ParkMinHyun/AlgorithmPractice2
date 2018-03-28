#include "stdafx.h"
#include<iostream>
using namespace std;

int A, B, C;
bool visit[201][201];
bool result[201];

void sol(int a, int b, int c) {

	if (visit[a][b]) {
		return;
	}

	visit[a][b] = true;

	if (a == 0) {
		result[c] = true;
	}

	//a->b,c
	if (B - b >= a) sol(0, a + b, c);
	else sol(a - (B - b), B, c);

	sol(0, b, a + c);
	//b->a,c
	if (A - a >= b) sol(a + b, 0, c);
	else sol(A, b - (A - a), c);

	sol(a, 0, b + c);
	//c->a,b
	if (A - a >= c) sol(a + c, b, 0);
	else sol(A, b, c - (A - a));

	if (B - b >= c) sol(a, b + c, 0);
	else sol(a, B, c - (B - b));

	return;
}

int main() {
	cin >> A >> B >> C;

	sol(0, 0, C);

	for (int i = 0; i <= 200; i++) {
		if (result[i]) cout << i << " ";
	}

	return 0;
}