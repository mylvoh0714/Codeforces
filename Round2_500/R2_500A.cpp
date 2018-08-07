#include <iostream>
int x[1001];
int y[1001];
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%d", &x[i]);
	}
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%d", &y[i]);
	}

	int ans = 0;
	for ( int i = 1; i <= n; i++ )
	{
		ans += x[i] - y[i];
	}
	if ( ans >= 0 )
		printf("Yes\n");
	else
		printf("No\n");
}