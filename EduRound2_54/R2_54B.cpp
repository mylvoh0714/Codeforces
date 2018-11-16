#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n; cin >> n;
	long long ans = 0;
	if ( n % 2 == 0 ) {
		ans = n / 2;
	}
	else {
		bool flag = false;
		for ( int i = 3; i <= sqrt(n) + 2; i++ )
		{
			if ( n%i == 0 ) {
				n -= i;
				ans += 1;
				flag = true;
				break;
			}
		}
		if ( flag == false ) {
			cout << 1 << '\n';
			return 0;
		}

		if ( n > 0 ) ans += n / 2;
	}
	cout << ans << '\n';
}