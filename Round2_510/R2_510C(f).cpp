#include <iostream>
#include <algorithm>
using namespace std;
int arr[200001];
int cnt;
int zeroArr[200001];
int zeroCnt;
int minusCnt;
int minusMax;
int minusMaxpos;

int main()
{
	int n; scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) 
	{
		int val; scanf("%d", &val);
		if ( val > 0 ) {
			arr[cnt++] = i;
		}
		else if ( val == 0 ) {
			zeroArr[zeroCnt++] = i;
		}
		else {
			arr[cnt++] = i;
			minusCnt++;
			if ( minusMax == 0 || minusMax < val ) {
				minusMaxpos = i;
				minusMax = val;
			}
		}
	}

	if ( zeroCnt >= 3 ) {
		for ( int i = 1; i < n; i++ )
		{
			printf("1 %d %d\n", i, i + 1);
		}
	}
	else if ( zeroCnt == 2 && minusCnt % 2 == 0 ) {
		printf("1 %d %d\n", zeroArr[0], zeroArr[1]);
		printf("2 %d\n", zeroArr[1]);
		for ( int i = 0; i < cnt-1; i++ )
		{
			printf("1 %d %d\n", arr[i], arr[i + 1]);
		}
	}
	else if ( zeroCnt == 2 && minusCnt % 2 == 1 ) {
		for ( int i = 1; i < n; i++ )
		{
			printf("1 %d %d\n", i, i + 1);
		}
	} 
	else if ( zeroCnt == 1 && minusCnt % 2 == 0 ) {
		printf("2 %d\n", zeroArr[0]);
		for ( int i = 0; i < cnt - 1; i++ )
		{
			printf("1 %d %d\n", arr[i], arr[i + 1]);
		}
	}
	else if ( zeroCnt == 1 && minusCnt % 2 == 1 ) {
		if ( zeroArr[0] < minusMaxpos ) {
			printf("1 %d %d\n", zeroArr[0], minusMaxpos);
			printf("2 %d\n", minusMaxpos);
		}
		else {
			printf("1 %d %d\n", minusMaxpos, zeroArr[0]);
			printf("2 %d\n", zeroArr[0]);
		}
		for ( int i = 0; i < cnt - 1; i++ )
		{
			if ( arr[i] == minusMaxpos ) continue;
			else if ( arr[i + 1] == minusMaxpos ) {
				if ( i + 2 < cnt ) {
					printf("1 %d %d\n", arr[i], arr[i + 2]);
				}
				i++;
				continue;
			}
			printf("1 %d %d\n", arr[i], arr[i + 1]);
		}
	}
	else if ( zeroCnt == 0 && minusCnt % 2 == 1 ) {
		printf("2 %d\n", minusMaxpos);
		for ( int i = 0; i < cnt - 1; i++ )
		{
			if ( arr[i] == minusMaxpos ) continue;
			else if ( arr[i + 1] == minusMaxpos ) {
				if ( i + 2 < cnt ) {
					printf("1 %d %d\n", arr[i], arr[i + 2]);
				}
				i++;
				continue;
			}
			printf("1 %d %d\n", arr[i], arr[i + 1]);
		}
	}
	else {
		for ( int i = 1; i < n; i++ )
		{
			printf("1 %d %d\n", i, i + 1);
		}
	}
	
}