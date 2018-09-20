#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	for ( int i = 0; i < t; i++ )
	{
		string s; cin >> s;
		int len = s.size();
		bool con[3]; // bool[0] = lowercon , [1] = uppercon, [2] = digitcon
		for ( int i = 0; i < 3; i++ ) con[i] = false;
		vector<int> noNeed;
		for ( int i = 0; i < len; i++ )
		{
			if ( s[i] >= 'a' && s[i] <= 'z' && con[0] == false ) con[0] = true;
			else if ( s[i] >= 'A' && s[i] <= 'Z' && con[1] == false ) con[1] = true;
			else if ( s[i] >= '0' && s[i] <= '9' && con[2] == false ) con[2] = true;
			else noNeed.push_back(i);
		}

		if ( con[0] * con[1] * con[2] == 1 ) {
			cout << s << '\n';
		}
		else {
			for ( auto itr = noNeed.begin(); itr != noNeed.end(); itr++ )
			{
				if ( con[0] * con[1] * con[2] == 1 ) break;
				if ( con[0] == false ) {
					s[*itr] = 'a';
					con[0] = true;
				}
				else if ( con[1] == false ) {
					s[*itr] = 'A';
					con[1] = true;
				}
				else {
					s[*itr] = '0';
					con[2] = true;
				}
			}
			cout << s << '\n';
		}
	}
}