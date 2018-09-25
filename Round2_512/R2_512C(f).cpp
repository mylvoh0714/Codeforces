#include <iostream>
#include <vector>
#include <string>
using namespace std;
int a[101];
int b[101];
int n, cnt, sum;
string ans = "NO";

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> cnt;

	for ( int i = 1; i <= cnt; i++ ) {
		int val; scanf("%1d", &val);
		if ( val != 0 ) {
			a[n+1] = val;
			sum += a[n+1];
			b[n+1] = sum;
			n++;
		}
	}
	if ( n == 0 ) {
		cout << "YES\n";
		return 0;
	}
	for ( int i = 1; i <= n; i++ ) {
		if ( sum%b[i] == 0 ) {
			int part_sum = 0;
			for ( int j = i + 1; j <= n; j++ ) {
				part_sum += a[j];
				if ( part_sum == b[i] && j != n) part_sum = 0;
				
				if ( part_sum > b[i] ) break;
			}
			if ( part_sum == b[i] ) {
				ans = "YES";
				break;
			}
		}
	}
	cout << ans << '\n';

}