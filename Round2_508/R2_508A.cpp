#include <iostream>
#include <string>
using namespace std;
int arr[27];

int main()
{
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	for ( int i = 0; i < n; i++ )
	{
		int idx = str[i] - 'A';
		arr[idx]++;
	}

	int less_cnt = -1;
	for ( int i = 0; i < k; i++ )
	{
		if ( less_cnt == -1 || arr[i] < less_cnt ) {
			less_cnt = arr[i];
		}
	}
	cout << less_cnt*k << '\n';
}
