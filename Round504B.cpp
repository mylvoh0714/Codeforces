#include <iostream>
using namespace std;
long long ans = 0;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long n, k;
	cin >> n >> k;
	if ( n + 1 >= k ) {
		ans = ( k - 1 ) / 2;
	}
	else {
		if ( n > k - n && k - n <= n ) {
			if ( k % 2 == 1 ) ans = k / 2 - ( k - n ) + 1;
			else ans = ( k - 1 ) / 2 - ( k - n ) + 1;
		}
		else ans = 0;
	}
	cout << ans << '\n';
}