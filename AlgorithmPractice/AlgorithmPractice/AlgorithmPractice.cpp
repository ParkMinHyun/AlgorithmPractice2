#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int N, len, result = 0;
	string str;

	cin >> N;
	while (N--) {
		result = 0;
		cin >> str;
		len = str.size();

		for (int i = 0; i < len; i++) {
			if (str[i] == '(')
				result++;

			else if (str[i] == ')') {
				if (result == 0) {
					result = -1;
					break;
				}
				result--;
			}
		}
		if (result == 0) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}