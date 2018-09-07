#include <iostream>
#include <algorithm>
using namespace std;
int a[500001];

int main()
{
	long long ans = 0;
	int minus_cnt = 0;

	int n; cin >> n;
	for ( int i = 0; i < n; i++ ) cin >> a[i];
	sort(a, a + n);
	for ( int i = 0; i < n - 1; i++ )
	{
		if ( a[i] < 0 ) {
			ans -= a[i];
			minus_cnt++;
		}
		else { // 양수. 즉 앞으로 계속 양수가 나온단 얘기
			if ( minus_cnt < 1 ) {
				ans -= a[i];
				minus_cnt++;
			}
			else {
				ans += a[i];
			}
		}
	}
	ans += a[n - 1];
	cout << ans << '\n';

}