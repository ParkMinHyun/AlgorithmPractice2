#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
vector<int> arrDFS;
int sum, num;

void DFS(int start) {

	arrDFS[start] = 1;
	for (int i = 1; i <= num; i++) {
		if (arr[start][i] == 1 && arrDFS[i] == 0) {
			DFS(i);
		}
	}
}

int main(void) {

	int N;
	cin >> N;
	while (N--) {
		int digit;
		cin >> num;
		
		sum = 0;
		arrDFS.clear();
		arr.clear();

		for (int i = 0; i <= num; i++) {
			vector<int> element;
			element.resize(num + 1);
			arr.push_back(element);
		}

		arrDFS.resize(num + 1);
		for(int i=0; i<num; i++){
			cin >> digit;
			arr[i+1][digit] = 1;
			arr[digit][i+1] = 1;
		}

		for (int i = 1; i <= num; i++) {
			if (arrDFS[i] == 0) {
				DFS(i);
				sum++;
			}
		}
		cout << sum << '\n';
	}

	return 0;
}