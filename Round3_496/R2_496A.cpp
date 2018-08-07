#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> arr(n+1);
	vector<int> ans;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
	}
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		if(arr[i] != arr[i+1]-1) {
			ans.push_back(arr[i]);
			cnt++;
		}
	}
	cout << cnt << '\n';
	for(int i=0;i<ans.size();i++)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
