#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	if ( n == 0 ) {
		cout << "0" << '\n';
		return 0;
	}
	n += 1;
	if ( n % 2 == 0 )
		cout << n / 2 << '\n';
	else
		cout << n << '\n';
}
