#include <iostream>
using namespace std;
int a[300001];
int b[300001];
long long aSum, bSum;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i];
		aSum += a[i];
	}
	int m; cin >> m;
	for ( int j = 1; j <= m; j++ ) {
		cin >> b[j];
		bSum += b[j];
	}

	if ( aSum != bSum ) {
		cout << "-1\n";
		return 0;
	}
	int i, j;
	i = j = 1;
	long long ans = 0;
	aSum = bSum = 0;
	while ( i <= n && j <= m )
	{
		if ( aSum + a[i] == bSum + b[j] ) {
			ans++;
			i++;
			j++;
			aSum = bSum = 0;
		}
		else if ( aSum + a[i] > bSum + b[j] ) {
			bSum += b[j];
			j++;
		}
		else {
			aSum += a[i];
			i++;
		}
	}
	if ( i == n + 1 && j == m + 1 ) {
		cout << ans << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}