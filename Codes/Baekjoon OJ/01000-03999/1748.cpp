#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll num; cin >> num;

    ll flag, digit;
    for (flag = 1, digit = 1; flag <= num; flag *= 10, digit++);
    flag /= 10, digit--;
    
    ll ans = (num - flag + 1) * digit;
    flag /= 10, digit--;
    for (; digit >= 1; flag /= 10, digit--) {
        ans += (9 * flag) * digit;
    }

    cout << ans << endl;

    return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 수학
결정적 깨달음		: 
시간복잡도		: O(log10n)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////