#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10000;

vector<int> childNode[MAX + 1];
vector<int> childValue[MAX + 1];
int parentNode[MAX + 1];
int parentValue[MAX + 1];

int treeDiameter(int nodeNum, int visited);

int main() {
	int t;
	cin >> t;

	for (int test = 0; test < t - 1; test++) {
		int parent, child, value;
		cin >> parent >> child >> value;

		childNode[parent].push_back(child);
		parentNode[child] = parent;

		childValue[parent].push_back(value);
		parentValue[child] = value;
	}
	
	int ans = 0;
	for (int i = 1; i <= MAX; i++) {
		if (childNode[i].size() != 0) continue;

		ans = max(ans, treeDiameter(i, 0));
	}

	cout << ans;

	return 0;
}

int treeDiameter(int nodeNum, int visited) {
	const int& parent = parentNode[nodeNum];
	const vector<int>& child = childNode[nodeNum];

	int pValue = 0, cValue = 0;
	
	if (parent != 0 && parent != visited)
		pValue = treeDiameter(parent, nodeNum) + parentValue[nodeNum];
	
	for (int i = 0; i < child.size(); i++) {
		if (child[i] == visited) continue;

		cValue = max(cValue, treeDiameter(child[i], nodeNum) + childValue[nodeNum][i]);
	}

	return max(cValue, pValue);
}
/*//////////////////////////////////////////////////////////////////////
문제 해법		: 배열을 이용한 트리 구현
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 1MB = 1000000byte. 문제의 메모리 제한은 128MB. int형 배열을 10001 * 10001 크기로 선언했으므로, 메모리 초과
				  2. 
*///////////////////////////////////////////////////////////////////////