#include <iostream>
using namespace std;
int n, q;

long long getNum(int n,int row,int col)
{
	long long ret = 0;

	int add = (n+1)/2;
	long long sum = row + col;
	if ( sum % 2 == 0 ) {
		ret = 1;
		if ( n % 2 == 0 ) {
			ret += add*(( row ) / 2) + ( add + 1 )*( (row-1) / 2 );
		}
		else ret += ( row - 1 )*add;

		if ( col < row ) ret -= ( row - col ) / 2;
		else if ( col > row ) ret += ( col - row ) / 2;
	}
	else
	{
		if ( ( n*n ) % 2 != 0 ) ret = ( n*n ) / 2 + 1;
		else ret = ( n*n ) / 2;

		if ( n % 2 == 0 ) {
			ret += add*( ( row - 1 ) / 2 ) + ( add + 1 )*( row / 2 );
		}
		else ret += ( row - 1 )*add;

		if ( col < row - 1 ) ret -= ( row - 1 - col ) / 2;
		else if ( col > row - 1 ) ret += ( col + 1 - row ) / 2;
	}
	return ret;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while ( 1 )
	{
		cin >> n;
		for ( int i = 1; i <= n; i++ )
		{
			for ( int j = 1; j <= n; j++ )
			{
				cout << getNum(n, i, j) << ' ';
			}
			cout << '\n';
		}
	}
	
	//cin >> n >> q;

	/*for ( int i = 0; i < q; i++ )
	{
		int row, col;
		cin >> row >> col;
		cout << getNum(n, row, col) << '\n';
	}*/
}