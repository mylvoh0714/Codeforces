#include <iostream>
#include <string>
using namespace std;
string a, l, r;
int aLen;
long long ans;
const int MOD = 998244353;

// return true if int(s1) <= int(s2)
bool diffstr(string& s1, string& s2)
{
	int s1Len = s1.size();
	int s2Len = s2.size();
	if ( s1Len < s2Len ) return true;
	else if ( s1Len > s2Len ) return false;
	else {
		for ( int i = 0; i < s1Len; i++ )
		{
			if ( s1[i] == s2[i] ) continue;

			if ( s1[i] < s2[i] ) {
				return true;
			}
			else {
				return false;
			}
		}
		return true;
	}
}

void go(int pos, string& s)
{
	if ( pos == aLen-1 ) {
		ans = ( ans + 1 ) % MOD;
		return;
	}
	if (pos != 0 && s != "0" ) {
		string newS = s + a[pos];
		if(diffstr(l,newS) && diffstr(newS,r)) go(pos + 1, newS);
	}
	s = "";
	s += a[pos];
	if ( diffstr(l, s) && diffstr(s, r) ) go(pos + 1, s);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> a >> l >> r;
	aLen = a.size();

	string start = "";
	go(0, start);
	cout << ans << '\n';
}