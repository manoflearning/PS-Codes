#include <iostream>
#include <algorithm>
using namespace std;

struct student {
	string name;
	int korean;
	int english;
	int math;
};

student students[100000];

bool compare(student& a, student& b);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> students[i].name;
		cin >> students[i].korean;
		cin >> students[i].english;
		cin >> students[i].math;
	}

	sort(students, students + n, compare);

	for (int i = 0; i < n; i++)
		cout << students[i].name << '\n';

	return 0;
}

bool compare(student& a, student& b) {
	if (a.korean != b.korean) return a.korean > b.korean;
	if (a.english != b.english) return a.english < b.english;
	if (a.math != b.math) return a.math > b.math;
	return a.name < b.name;
}
/*/////////////////////////////////////////////////////////////////////
문제 해법		: 
접근 방식		: 
결정적 깨달음		:
오답 원인		: 1.
				  2.
*//////////////////////////////////////////////////////////////////////