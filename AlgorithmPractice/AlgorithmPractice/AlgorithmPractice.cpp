#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

stack<int> iS, dS;

void enQueue(int v) {
	iS.push(v);
}

int deQueue() {
	
	if (dS.empty()) {
		while (!iS.empty()) {
			dS.push(iS.top());
			iS.pop();
		}	
	}
	
	return dS.top();
}

int main() {

	string input;
	int count, value;

	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> input;
		if (input == "E") {
			cin >> value;
			enQueue(value);
		}
		else if (input == "D") {
			cout << deQueue() << '\n';
			dS.pop();
		}
	}

	return 0;
}