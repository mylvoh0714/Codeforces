#include <iostream>
#include <string>
using namespace std;

int abs(int n)
{
	if ( n >= 0 ) return n;
	else return -n;
}

void _main(int TestCase)
{
	int n; cin >> n;
	string s;
	cin >> s;
	for ( int i = 0; i < n / 2; i++ )
	{
		if ( abs(s[i] - s[n - 1 - i]) > 2 || abs(s[i] - s[n-1-i]) == 1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	for ( int i = 0; i < t; i++ )
	{
		_main(i);
	}
}
