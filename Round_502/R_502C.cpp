#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int mid = n / 2 + 1;
	int idx = mid;
	while ( idx <= n )
	{
		cout << idx << ' ';
		idx++;
	}
	idx = 1;
	while ( idx <= mid - 1 )
	{
		cout << idx << ' ';
		idx++;
	}
}