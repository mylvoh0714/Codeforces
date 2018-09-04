#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string s1, s2;
	cin >> s1;
	cin >> s2;
	s1 = " " + s1;
	s2 = " " + s2;
	int idx = 0;
	int idx1 = 0;
	int idx2 = 0;
	for ( int i = 1; i<=n; i++ )
	{
		if ( s1[i] == '*' ) {
			idx = i;
			break;
		}

		if ( s1[i] != s2[i] ) {
			cout << "NO\n";
			return 0;
		}
		idx1++;
	}
	for ( int i = 1; i <= n; i++ )
	{
		if ( n+1-i <= idx ) break;
		if ( s1[n+1-i] != s2[m+1-i] ) {
			cout << "NO\n";
			return 0;
		}
		idx2++;
	}
	if ( idx1 <= m - idx2 + 1 ) cout << "YES\n";
	else cout << "NO\n";
}