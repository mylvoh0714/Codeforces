#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long ans = 1000000000000000000;
long long area;
long long diff_x, diff_y;

int main()
{
	int n; cin >> n;
	vector<int> arr(2 * n);
	for ( int i = 0; i < 2*n; i++ )
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	// iter = 0
	diff_x = arr[n - 1] - arr[0];
	diff_y = arr[2 * n - 1] - arr[n];
	area = diff_x*diff_y;
	ans = min(ans, area);

	// iter = 1~n-1 that is, xrange = [i,i+n] which i is [1,n-1]
	for ( int i = 1; i < n; i++ )
	{
		diff_x = arr[i + n - 1] - arr[i];
		diff_y = arr[2 * n - 1] - arr[0];
		area = diff_x*diff_y;
		ans = min(ans, area);
	}
	// iter = n
	diff_x = arr[2 * n - 1] - arr[n];
	diff_y = arr[n - 1] - arr[0];
	area = diff_x*diff_y;
	ans = min(ans, area);

	cout << ans << '\n';

}
