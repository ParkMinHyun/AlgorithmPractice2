#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string str;
	int subSum[3], temp, pos = 0;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {

		if (str[i] == '1' && str[i + 1] == '0') {
			temp = 10;
			i++;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			temp = str[i] - '0';
		}
		else if (str[i] == 'S') {
			subSum[pos++] = temp;
		}
		else if (str[i] == 'D') {
			subSum[pos++] = temp * temp;
		}
		else if (str[i] == 'T') {
			subSum[pos++] = temp * temp*temp;
		}
		else if (str[i] == '#') {
			subSum[pos - 1] *= -1;
		}
		else if (str[i] == '*') {
			if (pos == 1) {
				subSum[0] *= 2;
			}
			else {
				subSum[pos - 1] *= 2;
				subSum[pos - 2] *= 2;
			}
		}
	}

	cout << subSum[0] + subSum[1] + subSum[2] << '\n';

	return 0;
}