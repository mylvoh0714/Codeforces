#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	if ( n % 3 == 2 ) {
		cout << "1 ";
		cout << ( n - 1 ) / 2 << ' ';
		cout << ( n - 1 ) / 2;
	}
	else {
		cout << "1 " << "1 ";
		cout << n - 2;
	}
	cout << '\n';
}