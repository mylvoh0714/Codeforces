#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> split(string s)
{
	vector<int> ret;

	int idx = 0;
	int val = 0;
	while ( s[idx] != ' ' )
	{
		val = 10 * val + ( s[idx] - '0' );
		idx++;
	}
	ret.push_back(val);
	val = 0;

	idx++;

	while ( idx < s.size() )
	{
		val = 10 * val + ( s[idx] - '0' );
		idx++;
	}
	ret.push_back(val);

	return ret;
}

int main()
{
	string str;
	while ( getline(cin, str) )
	{
		vector<int> arr = split(str);
		int n, k;
		n = arr[0]; k = arr[1];
		
		int ans = 0;
		
		int dojang = 0;
		while ( n>0 )
		{
			ans += n;
			dojang += n;
			n = 0;

			if ( dojang >= k ) {
				n += dojang / k;
				dojang %= k;
			}
		}
		cout << ans << endl;
	}
}