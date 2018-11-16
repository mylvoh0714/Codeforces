#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	string str; cin >> str;
	char idx = -1;
	for ( int i = 1; i < str.size(); i++ )
	{
		if ( str[i - 1] - 'a' > str[i] - 'a' ) {
			idx = str[i - 1];
			break;
		}
	}
	if ( idx == -1 ) idx = str[n - 1];
	for ( auto itr = str.begin(); itr != str.end(); itr++ )
	{
		if ( *itr == idx ) {
			str.erase(itr);
			break;
		}
	}
	cout << str << '\n';
}