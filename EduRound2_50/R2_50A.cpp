#include <iostream>
using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	long long ans;

	if ( k%n == 0 ) ans = k / n;
	else ans = k / n + 1;
	cout << ans << '\n';
}