#include <iostream>
using namespace std;
int a[101];

int main()
{
	int n; cin >> n;

	int max = 0;
	int sum = 0;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
		sum += a[i];
		if ( max < a[i] ) max = a[i];
	}

	for ( int k = max;; k++ )
	{
		int sum2 = 0;
		for ( int i = 1; i <= n; i++ )
		{
			sum2 += k - a[i];
		}
		if ( sum2 > sum ) {
			cout << k << '\n';
			return 0;
		}
	}
}