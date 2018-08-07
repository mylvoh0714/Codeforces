#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int s1cnt[100];
int s2cnt[100];
int s3cnt[100];
int s1max, s2max, s3max;

int main()
{
	int n; cin >> n;
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	int len;
	len = s1.size();
	for ( int i = 0; i < len; i++ )
	{
		int temp = s1[i] - 'A';
		s1cnt[temp]++;
	}
	for ( int i = 0; i < 100; i++ )
	{
		if ( s1max < s1cnt[i] ) s1max = s1cnt[i];
	}

	len = s2.size();
	for ( int i = 0; i < len; i++ )
	{
		int temp = s2[i] - 'A';
		s2cnt[temp]++;
	}
	for ( int i = 0; i < 100; i++ )
	{
		if ( s2max < s2cnt[i] ) s2max = s2cnt[i];
	}

	len = s3.size();
	for ( int i = 0; i < len; i++ )
	{
		int temp = s3[i] - 'A';
		s3cnt[temp]++;
	}
	for ( int i = 0; i < 100; i++ )
	{
		if ( s3max < s3cnt[i] ) s3max = s3cnt[i];
	}

	if ( s1max + n > s1.size() ) {
		if ( n == 1 && s1max == s1.size()) s1max = s1.size() - 1;
		else s1max = s1.size();
	}
	else s1max += n;

	if ( s2max + n > s2.size() ) {
		if ( n == 1 && s2max == s2.size()) s2max = s2.size() - 1;
		else s2max = s2.size();
	}
	else s2max += n;

	if ( s3max + n > s3.size() ){
		if ( n == 1 && s3max == s3.size() ) s3max = s3.size() - 1;
		else s3max = s3.size();
	}
	else s3max += n;

	/*cout << s1max << '\n';
	cout << s2max << '\n';
	cout << s3max << '\n';*/

	if ( (s1max == s2max && s2max == s3max) || (s1max == s2max && s1max > s3max) || 
		(s2max == s3max && s1max < s2max) || (s1max == s3max && s2max < s1max) ) cout << "Draw\n";
	else {
		int maxval = max(s1max, max(s2max, s3max));
		if ( maxval == s1max ) cout << "Kuro\n";
		else if ( maxval == s2max ) cout << "Shiro\n";
		else cout << "Katie\n";
	}
}
