#include <iostream>
#include <string>
using namespace std;

bool neighborCondi(string &str)
{
	int len = str.size();
	if ( len == 1 ) return true;
	for ( int i = 0; i < len-1; i++ )
	{
		if ( str[i] == '1' && str[i + 1] == '1' )
			return false;
	}
	return true;
}
bool capacityCondi(string &str)
{
	int len = str.size();
	if ( len == 1 ) {
		if ( str == "0" ) return false;
		else if ( str == "1" ) return true;
	}

	if ( str[0] == '0' && str[1] == '0' ) return false; // idx = 0
	for ( int i = 1; i < len - 1; i++ ) // idx = 1~len-2
	{
		if ( str[i] == '0' ) {
			if ( str[i - 1] == '0' && str[i + 1] == '0' )
				return false;
		}
	}
	if ( str[len - 2] == '0' && str[len - 1] == '0' ) return false;
	return true;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int len; cin >> len;
	string str; cin >> str;

	if ( neighborCondi(str) && capacityCondi(str) ) cout << "Yes" << '\n';
	else cout << "NO" << '\n';
}
