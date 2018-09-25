#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, d, m;

bool check(int y, int x)
{
	if ( -d <= y - x && y - x <= d ) {
		if ( d <= y + x && y + x <= 2 * n - d ) {
			return true;
		}
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> d >> m;
	for ( int i = 0; i < m; i++ )
	{
		int y, x;
		cin >> y >> x;
		if ( check(y, x) ) cout << "YES\n";
		else cout << "NO\n";
	}
}