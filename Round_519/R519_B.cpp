#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int a[1001];
int x[1001];
const int INF = 10000000;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for ( int i = 1; i <= n; i++ ) cin >> a[i];

	int ans = 0;
	vector<int> ansVec;


	for ( int k = 1; k <= n; k++ )
	{
		for ( int i = 0; i <= n; i++ )
		{
			x[i] = INF;
		}

		for ( int i = 1; i <= n; i++ )
		{
			int idx = ( i - 1 ) % k;
			if ( x[idx] != INF ) {
				if ( x[idx] != a[i] - a[i - 1] ) {
					break;
				}
			}
			x[idx] = a[i] - a[i - 1];
			if ( i == n ) {
				ans++;
				ansVec.push_back(k);
			}
		}
	}
	cout << ans << '\n';
	for ( int i = 0; i < ansVec.size(); i++ ) cout << ansVec[i] << ' ';
}