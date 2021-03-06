#include <bits/stdc++.h>
using namespace std;

vector<int> sosu;
bool visited[32];

int arr[1005], color[1005];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    //sqrt(1000) 이하의 소수 모두 구하기
    sosu.push_back(2);
    for (int i = 4; i < 32; i += 2)
        visited[i] = true;
    for (int i = 3; i < 32; i += 2) {
        if (visited[i]) continue;
        sosu.push_back(i);
        for (int l = i * i; l < 32; l += 2 * i) {
            visited[l] = true;
        }
    }
    
    //테스트케이스 시작
	int T; cin >> T;

    while (T--) {
        int N; cin >> N;

        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        int c = 1;
        for (int s : sosu) {
            bool exist = false;
            for (int i = 1; i <= N; i++) {
                if (arr[i] % s == 0 && color[i] == 0) {
                    color[i] = c;
                    exist = true;
                }
            }
            if (exist) c++;
        }

        //출력
        cout << c - 1 << '\n';
        for (int i = 1; i <= N; i++) {
            cout << color[i] << ' ';
            color[i] = 0;
        }
        cout << '\n';
    }

	return 0;
}