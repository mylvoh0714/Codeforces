#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if ( b == 0 ) return a;
	else return gcd(b, a%b);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a(n + 1);

	int GCD = 0;
	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i];
		GCD = gcd( a[i], GCD );
	}
	sort(a.begin(), a.end());

	for ( int i = 1; i <= n; i++ ) a[i] /= GCD;
	int max_v = (int)sqrt(a[n]);
	vector<int> Eratos(max_v + 1);
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 2; j <= max_v; j++ ) {
			if ( a[i] % j == 0 ) Eratos[j] += 1;
		}
	}

	int ans = -1;
	for ( int j = 2; j <= max_v; j++ ) {
		if ( ans < Eratos[j] && Eratos[j] >= 2) ans = Eratos[j];
	}
	if ( ans == -1 ) {
		cout << ans << '\n';
	}
	else {
		ans = n - ans;
		cout << ans << '\n';
	}
}