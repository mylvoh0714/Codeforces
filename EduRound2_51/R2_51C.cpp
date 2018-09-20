#include <iostream>
#include <map>
using namespace std;
map<int, int> mp;
int a[104];
char ans[104];
bool odd_possible;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for ( int i = 1; i <= n; i++ ) ans[i] = 'A';

	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i];
		mp[a[i]] += 1;
	}
	int nice_cnt = 0;
	for ( int i = 1; i <= n; i++ )
	{
		if ( mp[a[i]] == 1 ) {
			nice_cnt++;
		}
		else if ( mp[a[i]] >= 3 ) {
			odd_possible = true;
		}
	}

	if ( ( ( nice_cnt & 1 ) && odd_possible == false) ) {
		cout << "NO\n";
		return 0;
	}
	else if ( ( nice_cnt & 1 ) && odd_possible == true ) {
		
		cout << "YES\n";
		nice_cnt /= 2;
		for ( int i = 1; i <= n; i++ )
		{
			if ( nice_cnt == 0 && odd_possible == false) break;
			if ( mp[a[i]] == 1 && nice_cnt > 0) {
				ans[i] = 'B';
				nice_cnt--;
			}
			if ( mp[a[i]] >= 3 && odd_possible == true) {
				ans[i] = 'B';
				odd_possible = false;
			}
		}
	}
	else {
		cout << "YES\n";
		nice_cnt /= 2;
		for ( int i = 1; i <= n; i++ )
		{
			if ( nice_cnt == 0 ) break;
			if ( mp[a[i]] == 1 ) {
				ans[i] = 'B';
				nice_cnt--;
			}
		}
	}
	for ( int i = 1; i <= n; i++ ) cout << ans[i];
}