#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	arr[1] += (n-1);
	for ( int i = 0; i < 4; i++ )
	{
		int temp; cin >> temp;
		arr[1] += temp * 10000;
	}
	int ans = 1;
	for ( int i = 2; i <= n; i++ )
	{
		arr[i] += (n-i);
		for ( int j = 0; j < 4; j++ )
		{
			int temp; cin >> temp;
			arr[i] += temp * 10000;
		}
		if ( arr[i] > arr[1] ) ans++;
	}
	cout << ans << '\n';
}