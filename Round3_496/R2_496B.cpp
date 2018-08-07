#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s1,s2;
	cin >> s1 >> s2;
	int len1 = s1.size();
	int len2 = s2.size();
	int idx1,idx2;
	idx1 = idx2 = 0;
	long long ans = 0;
	if(len1 < len2) {
		int diff = len2-len1;
		ans += diff;
		ans += len1*2;
		for(int i=0;i<len1;i++)
		{
			if(s2[len2-1-i]==s1[len1-1-i]) {
				ans -= 2;
			}
			else {
				break;
			}
		}
	}
	else if ( len1 > len2) {
		int diff = len1-len2;
		ans += diff;
		ans += len2*2;
		for(int i=0;i<len2;i++)
		{
			if(s1[len1-1-i] == s2[len2-1-i]) {
				ans -= 2;
			}
			else {
				break;
			}
		}			
	}
	else {
		ans += len1*2;
		for(int i=0;i<len1;i++)
		{
			if(s1[len1-1-i] == s2[len2-1-i]) {
				ans -= 2;
			}
			else {
				break;
			}
		}
	}
	cout << ans << '\n';
}
