#include <iostream>
#include <vector>
#include <map>
using namespace std;
int ans;
int power2[31];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	power2[0] = 1;
	for(int i=1;i<31;i++)
	{
		power2[i] = power2[i-1]*2;
	}

	int n;
	cin >> n;
	vector<int> arr(n);
	map<int,int> check;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		check[arr[i]] += 1;
	}

	for(int i=0;i<n;i++)
	{
		bool flag = false;
		for(int j=0;j<31;j++)
		{
			int key = power2[j] - arr[i];
			if(key < 0) continue;
			if(check[key]) {
				if(key==arr[i] && check[key] >= 2) {
					flag = true;
					break;
				} else if (key != arr[i]){
					flag = true;
					break;
				}
			}
		}
		if(flag == false) ans++;
	}
	cout << ans << '\n';
}
