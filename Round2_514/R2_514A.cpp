#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, l, a;
	cin >> n >> l >> a;
	int ans = 0;
	vector<pair<int,int>> arr(n+1);
	for ( int i = 1; i <= n; i++ )
	{
		cin >> arr[i].first >> arr[i].second;
		arr[i].second += arr[i].first;
		ans += ( arr[i].first - arr[i - 1].second ) / a;
	}
	ans += ( l - arr[n].second ) / a;
	cout << ans << '\n';
}