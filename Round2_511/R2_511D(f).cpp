#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if ( n > m ) { // setting for n <= m
		int temp = n;
		n = m;
		m = temp;
	}

	long long ans = 0;
	if ( n == 1 ) {
		if ( m < 3 ) ans = 0;
		else ans = m - 3;
	}
	else if ( n == 2 ) {
		if ( m < 3 ) ans = 0;
		else ans = 2 * ( m - 2 );
	}
	else if ( n == 3 ) {
		ans = 6 * m - 10; // m >= 3
	}
	else {
		ans = 2 * ( n - 2 ) + ( m - 2 )*( 4 * n - 6 );
	}
	cout << ans << '\n';
}