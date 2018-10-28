#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[23];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string str;
	getline(cin, str);
	int val; cin >> val;
	int n = 1;
	for ( int i = 0; i < str.size(); i++ )
	{
		if ( str[i] >= '0' && str[i] <= '9' ) {
			a[n++] = str[i] - '0';
		}
	}
	n--;
	
	sort(a + 1, a + 1 + n);
	bool flag = false;
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = i + 1; j <= n; j++ )
		{
			for ( int k = j + 1; k <= n; k++ )
			{
				if ( a[i] + a[j] + a[k] == val ) {
					cout << a[i] << ' ' << a[j] << ' ' << a[k] << '\n';
					flag = true;
				}
			}
		}
	}
	if ( flag == false ) cout << "NO\n";
	
	//for ( int i = 1; i <= n; i++ ) cout << a[i] << endl;
}