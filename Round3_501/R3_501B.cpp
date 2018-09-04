#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s, t;
	cin >> s; 
	cin >> t; 
	int pos = -1;
	vector<int> ans;
	for ( int i = 0; i < n; i++ )
	{
		if ( s[i] == t[i] ) continue;
		int pos, idx;
		pos = idx = i;
		while ( idx < n && s[idx] != t[pos] ) idx++;
		if ( idx == n ) {
			cout << "-1\n";
			return 0;
		}
		while ( idx != pos )
		{
			ans.push_back(idx - 1);
			char temp = s[idx];
			s[idx] = s[idx - 1];
			s[idx - 1] = temp;
			idx--;
		}
	}
	cout << ans.size() << '\n';
	for ( int i = 0; i < ans.size(); i++ ) cout << ans[i]+1 << ' ';
	cout << '\n';

	return 0;
}