#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int>> arr;
int main() {
	int N;
	cin >> N;
	while (N--) {
		int x, y;
		cin >> x >> y;

		arr.push_back(make_pair(y, x));
	}
	
	sort(arr.begin(),arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].second << ' ' << arr[i].first << '\n';
	}
}