#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pint;
vector<int> ans;
priority_queue< pint > pq;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector< pint > arr(n + 1);
	
	for ( int i = 1; i <= n; i++ )
	{
		int temp; cin >> temp;
		arr[i] = { temp,i };
	}
	sort(arr.begin()+1, arr.end());
	int idx1 = 1;

	string s; cin >> s;
	for ( int i = 0; i < 2 * n; i++ )
	{
		if ( s[i] == '0' ) {
			ans.push_back(arr[idx1].second);
			pq.push(arr[idx1]);
			idx1++;
		}
		else if ( s[i] == '1' ) {
			pint here = pq.top();
			pq.pop();
			ans.push_back(here.second);
		}
	}
	
	for ( int i = 0; i < ans.size(); i++ )
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
