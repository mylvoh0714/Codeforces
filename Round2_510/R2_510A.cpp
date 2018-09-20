#include <iostream>
#include <algorithm>
using namespace std;
int arr[101];

int main()
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	int max_v = 0;
	int sum = 0;
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%d", &arr[i]);
		if ( max_v < arr[i] ) max_v = arr[i];
		sum += arr[i];
	}
	sum += m;
	int min_ans = 0;
	int max_ans = 0;
	int avg = sum % n == 0 ? sum / n : sum / n + 1;
	min_ans = max(max_v, avg);
	max_ans = max_v + m;
	printf("%d %d\n", min_ans, max_ans);
}