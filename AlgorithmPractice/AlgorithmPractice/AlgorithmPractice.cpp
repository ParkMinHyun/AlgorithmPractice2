#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string A, B, temp;
	getline(cin, A);
	getline(cin, B);

	transform(A.begin(), A.end(), A.begin(), toupper);
	transform(B.begin(), B.end(), B.begin(), toupper);

	vector<string> aSet;
	vector<string> bSet;

	vector<string> interS;
	vector<string> unionS;

	for (int i = 1; i < A.size(); i++) {
		if (A[i - 1] < 'A' || A[i] <'A' || A[i - 1] > 'Z' || A[i] >'Z') {
			continue;
		}
		temp = A[i - 1];
		temp += A[i];
		aSet.push_back(temp);
	}

	for (int i = 1; i < B.size(); i++) {
		if (B[i - 1] < 'A' || B[i] <'A' || B[i - 1] > 'Z' || B[i] >'Z') {
			continue;
		}
		temp = B[i - 1];
		temp += B[i];
		bSet.push_back(temp);
	}

	for (int i = 0; i < bSet.size(); i++) {
		unionS.push_back(bSet[i]);

		auto it = find(aSet.begin(), aSet.end(), bSet[i]);
		if (it != aSet.end()) {
			aSet.erase(it);
			interS.push_back(bSet[i]);
		}
	}

	int aSetSize = aSet.size();
	for (int i = 0; i < aSetSize; i++) {
		unionS.push_back(aSet[i]);
	}

	float result = interS.size() / (float)unionS.size();

	cout << (int)(result * 65536) << '\n';
	return 0;
}