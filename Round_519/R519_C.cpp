#include <iostream>
#include <string>
using namespace std;
int a[1001];

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	bool flag = false;
	for ( int i = n - 1; i > 0; i-- )
	{
		if ( flag == false ) {
			if ( s[i] == 'a' ) {
				a[i] = 1;
				flag = true;
			}
			else
				a[i] = 0;
		}
		else if ( flag == true ) {
			if ( s[i] == 'b' ) {
				a[i] = 1;
				flag = false;
			}
		}
	}
	for ( int i = 0; i < n; i++ )
	{
		cout << a[i] << ' ';
	}
}