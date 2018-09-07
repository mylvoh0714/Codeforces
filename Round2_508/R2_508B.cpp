#include <cstdio>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	if ( n == 1 || n == 2 ) printf("No\n");
	else {
		printf("Yes\n");
		printf("%d ", n - 1);
		for ( int i = 1; i < n; i++ ) printf("%d ", i);
		printf("\n");
		printf("1 %d\n", n);
	}
}
