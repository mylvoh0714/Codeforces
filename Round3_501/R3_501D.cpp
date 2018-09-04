#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll n, k, s;

ll go(ll cur, ll dist)
{
	if ( cur - dist > 0 )
		return cur - dist;
	else
		return cur + dist;
}

int main()
{
	cin >> n >> k >> s;
	if ( k > s || k*( n - 1 ) < s ) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	ll diff, cur;
	cur = 1;
	while ( k > 0 )
	{
		diff = min(n - 1, s - ( k - 1 ));
		cur = go(cur, diff);
		cout << cur << ' ';
		s -= diff;
		k--;
	}
}