#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s; cin >> s;
	int cnt1 = 0;
	string ans;
	for ( auto c:s )
	{
		if ( c == '1' ) cnt1++;
		else ans += c;
	}

	int len = ans.size();
	int pos = -1;
	for ( int i=0;i<len;i++)
	{
		if ( ans[i] == '2' ) {
			pos = i;
			break;
		}
	}
	if ( pos == -1 ) pos = len;
	
	ans.insert(pos, string(cnt1,'1'));
	cout << ans << '\n';
	
}
