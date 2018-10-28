#include <iostream>
using namespace std;
int maxdigit[11];
int a[11];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for ( int i = 1; i <= n; i++ ) cin >> maxdigit[n+1-i];
	for ( int i = 1; i <= n; i++ ) {
		cin >> a[n + 1 - i];
		if ( a[n + 1 - i] > maxdigit[n + 1 - i] ) {
			cout << -1 << '\n';
			return 0;
		}
	}
	int cnt; cin >> cnt;
	
	a[1] += cnt;
	for ( int i = 1; i <= n; i++ )
	{
		a[i + 1] += a[i] / ( maxdigit[i] + 1 );
		a[i] %= maxdigit[i] + 1;
	}
	for ( int i = n; i >= 1; i-- ) cout << a[i];
}