#include <iostream>
using namespace std;
int arr[100001];
int visited[100001];
int visited2[100001];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; int x; // x = and연산할값
	cin >> n >> x;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> arr[i];
		if ( visited[arr[i]] ) {
			cout << "0\n";
			return 0;
		}
		visited[arr[i]]++;
	}

	bool flag = false;
	for ( int i = 1; i <= n; i++ )
	{
		int temp = arr[i] & x;
		if ( visited[temp] && arr[i] != temp ) {
			cout << "1\n";
			return 0;
		}
		if ( visited2[temp] ) {
			flag = true;
		}
		visited2[temp]++;
	}

	if ( flag == true ) {
		cout << "2\n";
	}
	else {
		cout << "-1\n";
	}
} 
