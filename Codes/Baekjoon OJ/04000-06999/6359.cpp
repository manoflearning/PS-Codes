#include <iostream>
#include <vector>
using namespace std;

enum j {
	open = true,
	close = false
};

int n;
vector<bool> jail;

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		scanf("%d", &n);

		jail.resize(n, j::close);

		for (int i = 0; i < n; i++) {
			for (int l = i; l < n; l += i + 1) {
				if (jail[l] == j::open) jail[l] = j::close;
				else jail[l] = j::open;
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (jail[i] == j::open) ans++;
		}

		printf("%d\n", ans);

		jail.clear();
	}

	return 0;
}
/*
���� �ع�		: ���� Ž��
���� ���		: 
������ ������	: 
���� ����		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////