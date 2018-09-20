#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long s[200001]; // sum

long long sum(vector<long long> &tree, int pos) {
	long long ans = 0;
	while ( pos > 0 ) {
		ans += tree[pos];
		pos &= ( pos - 1 );
		//pos -= ( pos & -pos ); # same result.
	}
	return ans;
}

void update(vector<long long> &tree, int pos, long long diff) {
	while ( pos < tree.size() ) {
		tree[pos] += diff;
		pos += ( pos & -pos );
	}
}

int main()
{
	/*cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; long long t;
	cin >> n >> t;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> s[i];
		s[i] += s[i - 1];
	}*/
}