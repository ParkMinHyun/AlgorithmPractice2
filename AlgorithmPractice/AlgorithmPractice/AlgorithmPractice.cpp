#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	int E, S, M, cnt = 1;

	cin >> E >> S >> M;

	E %= 15;
	S %= 28;
	M %= 19;

	while (true) {
		
		if (cnt % 15 == E && cnt % 28 == S && cnt % 19 == M) {
			cout << cnt << '\n';
			break;
		}
		cnt++;
	}
	return 0;
}