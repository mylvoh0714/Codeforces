#include <iostream>
#include <vector>
using namespace std;
int a[1000001];
int b[24];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> ans;
	int n; cin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 2; j <= n; j *= 2 )
		{
			if ( i%j != 0 ) break;
			a[i]++;
		}
	}
	for ( int i = 1; i <= n; i++ )
	{
		b[a[i]] += 1;
	}
	int max = 0;
	for ( int i = 0; b[i] != 0; i++ )
	{
		if ( max < b[i] ) max = b[i];
	}
	for ( int i = 0; b[i] != 0; i++ )
	{
		for ( int j = 0; j < b[i]; j++ )
		{
			ans.push_back(1 << i);
		}
	}
	
	if ( n == 1 ) {
		cout << "1" << '\n';
		return 0;
	}
	else if ( n == 3 ) {
		cout << "1 1 3" << '\n';
		return 0;
	}
	else {
		int val = ans[n - 1];
		/*cout << "the val : " << a[val] << endl;
		cout << "max : " << max << endl;*/
		for ( int i = n; i >= max; i-- )
		{
			if ( a[i] >= a[val] - 1 ) {
				/*cout << "i, a[i]" << i << ',' << a[i] << '\n';*/
				ans.pop_back();
				ans.push_back(i);
				break;
			}
		}
		for ( int i = 0; i < n; i++ )
		{
			cout << ans[i] << ' ';
		}
	}
	
}