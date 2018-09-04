#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> arr(m + 1);
	int ans = 0;
	for ( int i = 1; i <= n; i++ )
	{
		int s, e;
		cin >> s >> e;
		for ( int j = s; j <= e; j++ )
		{
			if ( arr[j] == 0 ) {
				arr[j] = 1;
				ans++;
			}
		}
	}
	cout << m-ans << '\n';
	for ( int i = 1; i <= m; i++ )
	{
		if ( arr[i] == 0 ) cout << i << ' ';
	}
	cout << '\n';
	
}