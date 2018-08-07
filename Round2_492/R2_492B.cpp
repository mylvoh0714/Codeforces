#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> arr(n+1);
	int min = 1 << 30;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		if(arr[i]< min) {
			min = arr[i];
		}
	}
	int k = 0;
	int ans = 0;
	for(k = min/n;;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(arr[i] <= k*n+i-1) {
				ans = i;
				cout << ans << '\n';
				return 0;
			}
		}
	}
	
}
