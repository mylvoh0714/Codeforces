#include <iostream>
#include <vector>
using namespace std;

long long myabs(int a)
{
	long long ret = (long long)a;
	if ( ret >= 0 ) return ret;
	else return -ret;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<long long> arr(N + 1);
	long long sumx = 0;
	long long posit_sumd = 0;
	long long negat_sumd = 0;
	for ( int query = 1; query <= M; query++ )
	{
		int x, d;
		scanf("%d %d", &x, &d);
		sumx += x;
		if ( d >= 0 ) {
			posit_sumd += d;
		}
		else {
			negat_sumd += d;
		}
	}
	int p_pos = 1;
	int n_pos = ( N + 1 ) / 2;
	long long sum = 0;
	for ( int i = 1; i <= N; i++ )
	{
		arr[i] = sumx + posit_sumd*( myabs(p_pos - i) ) + negat_sumd*( myabs(n_pos - i) );
		sum += arr[i];
	}

	printf("%.15f\n", double(sum) / N);
}
