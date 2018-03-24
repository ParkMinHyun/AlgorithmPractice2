#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int cSize, time = 0;
	string city;
	cin >> cSize;

	vector<string> arr;
	while (getline(cin, city, ',')) {

		transform(city.begin(), city.end(), city.begin(), toupper);

		if (arr.size() < cSize) {
			arr.push_back(city);
			time += 5;
			continue;
		}

		auto it = find(arr.begin(), arr.end(), city);
		if (it == arr.end()) {
			arr.erase(arr.begin());
			arr.push_back(city);
			time += 5;
		}
		else {
			arr.erase(it);
			arr.push_back(city);
			time += 1;
		}

		cout << time << '\n';
	}
	return 0;
}