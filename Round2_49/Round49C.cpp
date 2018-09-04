#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int arr[10001];

void _main(int TestCase)
{
	vector<int> vec;
	memset(arr, 0, sizeof(arr));
	int n; cin >> n;
	for ( int i = 0; i < n; i++ )
	{
		int temp; cin >> temp;
		arr[temp] += 1;
		if ( arr[temp] == 2 || arr[temp] == 4 ) vec.push_back(temp);
	}
	int ansStick1, ansStick2;

	sort(vec.begin(), vec.end());

	int len = vec.size();
	double ans = -1;
	for ( int i = 0; i < len - 1; i++ )
	{
		if ( ans == -1 || ( vec[i + 1] * vec[i + 1] + vec[i] * vec[i] ) / ( vec[i + 1] * vec[i] * 1.00 ) < ans ) {
			ans = ( vec[i + 1] * vec[i + 1] + vec[i] * vec[i] ) / ( vec[i + 1] * vec[i] * 1.00 );
			ansStick1 = vec[i + 1];
			ansStick2 = vec[i];
		}
	}

	for ( int i = 0; i < 2; i++ ) cout << ansStick1 << ' ';
	for ( int i = 0; i < 2; i++ ) cout << ansStick2 << ' ';
	cout << '\n';

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	for ( int i = 0; i < t; i++ )
	{
		_main(i);
	}
}
