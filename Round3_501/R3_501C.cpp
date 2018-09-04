#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a1(n + 1);
	vector<int> a2(n + 1);
	vector<long long> diff;
	long long s1, s2; // sum of a1,a2
	s1 = s2 = 0;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a1[i] >> a2[i];
		diff.push_back(a1[i] - a2[i]);
		s1 += a1[i];
		s2 += a2[i];
	}
	sort(diff.begin(), diff.end());
	reverse(diff.begin(), diff.end());

	if ( m < s2 ) {
		cout << "-1\n";
		return 0;
	}
	if ( s1 <= m ) {
		cout << "0\n";
		return 0;
	}

	int ans = 0;
	for ( int i = 0; i < n; i++ )
	{
		s1 -= diff[i];
		ans++;
		if ( s1 <= m ) {
			cout << ans << '\n';
			return 0;
		}
	}
}