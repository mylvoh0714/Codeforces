#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int visited[51][51];
int cnt;
int maxDistance;
int row, col;
int dy[] = { 2,2,-2,-2,1,1,-1,-1 };
int dx[] = { 1,-1,1,-1,2,-2,2,-2 };

bool check(int r, int c)
{
	if ( 1 <= r && r <= row && 1 <= c && c <= col ) return true;
	else return false;
}

int main()
{
	cin >> row >> col;
	if ( row <= 0 || col <= 0 ) {
		cout << -1 << '\n';
		return 0;
	}
	queue<pair<int, int>> q;
	
	visited[1][1] = 1;
	cnt++;
	q.push({ 1,1 });
	while ( !q.empty() )
	{
		int h_row = q.front().first;
		int h_col = q.front().second;
		q.pop();

		for ( int i = 0; i < 8; i++ )
		{
			int t_row = h_row + dy[i];
			int t_col = h_col + dx[i];
			if ( check(t_row, t_col) && !visited[t_row][t_col] ) {
				q.push({ t_row,t_col });
				visited[t_row][t_col] = visited[h_row][h_col] + 1;
				if ( maxDistance < visited[t_row][t_col] ) maxDistance = visited[t_row][t_col] - 1;
				cnt++;
			}
		}
	}
	if ( cnt == row*col ) cout << "T";
	else cout << "F";

	cout << maxDistance;
}