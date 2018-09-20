#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int INF = 100001;
int c[7];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for ( int i = 0; i < 7; i++ ) c[i] = INF;

	int n; cin >> n;
	for ( int i = 0; i < n; i++ )
	{
		int price;
		string s;
		cin >> price >> s;
		if ( s == "A" ) {
			c[0] = min(c[0], price);
		}
		else if ( s == "B" ) {
			c[1] = min(c[1], price);
		}
		else if ( s == "C" ) {
			c[2] = min(c[2], price);
		}
		else if ( s == "AB" || s == "BA" ) {
			c[3] = min(c[3], price);
		}
		else if ( s == "BC" || s == "CB" ) {
			c[4] = min(c[4], price);
		}
		else if ( s == "CA" || s == "AC" ) {
			c[5] = min(c[5], price);
		}
		else if ( s == "ABC" || s == "ACB" || s == "BAC" || s == "BCA" || s == "CAB" || s == "CBA" ) {
			c[6] = min(c[6], price);
		}
	}
	int ans = 300001;
	if ( c[0] != INF && c[1] != INF && c[2] != INF ) ans = min(ans, c[0] + c[1] + c[2]);
	if ( c[3] != INF && c[2] != INF ) ans = min(ans, c[3] + c[2]);
	if ( c[4] != INF && c[0] != INF ) ans = min(ans, c[4] + c[0]);
	if ( c[5] != INF && c[1] != INF ) ans = min(ans, c[5] + c[1]);
	if ( c[6] != INF ) ans = min(ans, c[6]);
	if ( c[3] != INF && c[4] != INF ) ans = min(ans, c[3] + c[4]);
	if ( c[4] != INF && c[5] != INF ) ans = min(ans, c[4] + c[5]);
	if ( c[3] != INF && c[5] != INF ) ans = min(ans, c[3] + c[5]);
	if ( ans == 300001 ) cout << -1 << '\n';
	else cout << ans << '\n';