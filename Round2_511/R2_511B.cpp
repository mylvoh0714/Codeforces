#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	long long ans = 0;
	for ( int i = 0; i < n; i++ ) {
		int a, b;
		cin >> a >> b;
		if ( ans < a + b ) ans = a + b;
	}
	cout << ans << '\n';
}