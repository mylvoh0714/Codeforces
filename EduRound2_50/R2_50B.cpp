#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int q; cin >> q;
	for ( int query = 0; query < q; query++ )
	{
		long long x, y, k;
		cin >> x >> y >> k;
		if ( x < 0 ) x = -x;
		if ( y < 0 ) y = -y;

		long long ans = 0;
		if ( x == y ) {
			if ( x > k ) {
				cout << -1 << '\n';
				continue;
			}
			ans += x;
			k -= x;
			if ( k == 1 ) {
				ans--;
			}
			else { 
				if ( k % 2 == 0 ) ans += k; // k°¡ 1ÀÌ¾Æ´Ï°í, Â¦¼ö
				else ans += k - 2; // k°¡ 1ÀÌ¾Æ´Ï°í, È¦¼ö
			}
		}
		else { // x != y
			long long min_v = min(x, y);
			long long max_v = max(x, y);
			ans += min_v;
			max_v -= min_v;
			k -= min_v;
			if ( k - max_v >= 0 ) {
				if (max_v % 2 == 0 ) { // Â¦¼ö
					if ( k % 2 == 0 ) ans += k;
					else ans += k - 2;
				}
				else { // È¦¼ö
					ans += k - 1;
				}
			}
			else {
				ans = -1;
			}
			
		}
		cout << ans << '\n';
	}
}