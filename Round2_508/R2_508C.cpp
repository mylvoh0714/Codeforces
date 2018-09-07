#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int b[100001];
long long a_score, b_score;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for ( int i = 0; i < n; i++ ) cin >> a[i];
	for ( int i = 0; i < n; i++ ) cin >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	int a_idx = n - 1;
	int b_idx = n - 1;
	
	while ( a_idx >= 0 || b_idx >= 0 )
	{
		// a turn
		if ( a_idx < 0 ) b_idx--;
		else if ( b_idx < 0 ) {
			a_score += a[a_idx];
			a_idx--;
		}
		else {
			if ( a[a_idx] <= b[b_idx] ) {
				b_idx--;
			}
			else {
				a_score += a[a_idx];
				a_idx--;
			}
		}
		
		// b turn
		if ( b_idx < 0 ) a_idx--;
		else if ( a_idx < 0 ) {
			b_score += b[b_idx];
			b_idx--;
		}
		else {
			if ( a[a_idx] >= b[b_idx] ) {
				a_idx--;
			}
			else {
				b_score += b[b_idx];
				b_idx--;
			}
		}
	}

	cout << a_score - b_score << '\n';
}