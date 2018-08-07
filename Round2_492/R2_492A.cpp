#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int ans = 0;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ans += n/100;
	n %= 100;
	ans += n/20;
	n %= 20;
	ans += n/10;
	n %= 10;
	ans += n/5;
	n %= 5;
	ans += n;
	cout << ans << '\n';
}
