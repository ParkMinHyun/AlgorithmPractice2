#include "stdafx.h"
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

string str, temp;
deque<int> D;
bool reverseCheck;

void check() {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'R') {
			reverseCheck = !reverseCheck;
		}
		else if (str[i] == 'D') {
			if (D.empty()) {
				cout << "error" << endl;
				return;
			}
			if (reverseCheck)
				D.pop_back();
			else
				D.pop_front();
		}
	}

	if (reverseCheck)
		reverse(D.begin(), D.end());

	int decSize = D.size();
	cout << "[";
	for (int i = 0; i < decSize - 1; i++)
		cout << D[i] << ",";
	cout << D[decSize - 1] << "]" << '\n';
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		int size;
		cin >> str >> size >> temp;

		reverseCheck = false;
		D.clear();

		string num;
		temp.erase(temp.begin());
		if (temp[0] == ']') {
			cout << "error" << endl;
			continue;
		}
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] >= '0' && temp[i] <= '9') {
				num += temp[i];
			}
			else {
				D.push_back(stoi(num));
				num.clear();
			}
		}
		check();
	}
}