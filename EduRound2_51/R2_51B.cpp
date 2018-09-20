#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long l, r;
	cin >> l >> r;
	cout << "YES\n";
	for ( long long i = l; i < r; i++ )
	{
		cout << i << ' ' << i + 1 << '\n';
		i++;
	}
}