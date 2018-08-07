#include <iostream>
using namespace std;
int arr[1001]; // game
int c[1001]; // cost
int paid[1001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%d", &arr[i]);
	}
	for ( int i = 1; i <= m; i++ )
	{
		scanf("%d", &c[i]);
	}

	int ans = 0;
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			if ( paid[j] ) continue;
			if ( arr[i] <= c[j] ) {
				ans++;
				paid[j] = 1;
				break;
			}
			else {
				break;
			}
		}
	}
	printf("%d\n", ans);
}
