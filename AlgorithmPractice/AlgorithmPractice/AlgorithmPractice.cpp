#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	getline(cin, str);

	int len = str.size();
	for (int i = 0; i < len; i++) {

		char currentStr = str[i];
		if (currentStr >= 'a' && currentStr <= 'z')
			currentStr = (currentStr - 'a' + 13) % 26 + 'a';

		else if (currentStr >= 'A' && currentStr <= 'Z')
			currentStr = (currentStr - 'A' + 13) % 26 + 'A';

		cout << currentStr;
	}

}