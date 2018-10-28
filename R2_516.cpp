#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int map[2001][2001];
int visited[2001][2001];
int leftvisited[2001][2001];
int rightvisited[2001][2001];

int n, m;
int ans;

typedef struct _maze {
	int row;
	int col;
	int left_c;
	int right_c;
}maze;

bool check(int row, int col)
{
	return ( 1 <= row ) && ( row <= n ) && ( 1 <= col ) && ( col <= m );
}


void bfs(int row, int col, int left_c, int right_c)
{
	maze m = { row,col,left_c,right_c };
	queue<maze> q;
	q.push(m);

	while ( !q.empty() )
	{
		int h_row = q.front().row;
		int h_col = q.front().col;
		int h_left_c = q.front().left_c;
		int h_right_c = q.front().right_c;
		visited[h_row][h_col] = 1;
		leftvisited[h_row][h_col] = h_left_c;
		rightvisited[h_row][h_col] = h_right_c;
		q.pop();

		if ( map[row + 1][col] && check(row + 1, col) && (!visited[row + 1][col] ||
				leftvisited[row+1][col] < h_left_c || rightvisited[row+1][col] < h_right_c)) {
			q.push({ row + 1,col,h_left_c,h_right_c });
		}

		if ( map[row - 1][col] && check(row - 1, col) && (!visited[row - 1][col] ||
				leftvisited[row-1][col] < h_left_c || rightvisited[row-1][col] < h_right_c)) {
			q.push({ row - 1,col,h_left_c,h_right_c });
		}

		if ( map[row][col + 1] && check(row, col + 1) && right_c > 0 && (!visited[row][col + 1] ||
				leftvisited[row][col+1] < h_left_c || rightvisited[row][col+1] < h_right_c+1)) {
			q.push({ row,col + 1,h_left_c,h_right_c - 1 });
		}

		if ( map[row][col - 1] && check(row, col - 1) && left_c > 0 && (!visited[row][col - 1] ||
				leftvisited[row][col-1] < h_left_c+1 || rightvisited[row][col-1] < h_right_c )) {
			q.push({ row,col - 1,h_left_c - 1,h_right_c });
		}
	}
}

//void dfs(int row, int col, int left_c, int right_c)
//{
//	visited[row][col] = 1;
//	leftvisited[row][col] = left_c;
//	rightvisited[row][col] = right_c;
//
//	if ( map[row + 1][col] && check(row + 1, col) ) {
//		if(!visited[row+1][col] || leftvisited[row+1][col] < left_c || rightvisited[row+1][col] < right_c)
//			dfs(row + 1, col, left_c, right_c);
//	}
//
//	if ( map[row - 1][col] && check(row - 1, col) ) {
//		if ( !visited[row - 1][col] || leftvisited[row - 1][col] < left_c || rightvisited[row - 1][col] < right_c )
//			dfs(row - 1, col, left_c, right_c);
//	}
//
//	if ( map[row][col + 1] && check(row, col + 1) && right_c > 0) {
//		if ( !visited[row][col+1] || leftvisited[row][col+1] < left_c || rightvisited[row][col+1] < right_c )
//			dfs(row, col + 1, left_c, right_c - 1);
//	}
//
//	if ( map[row][col - 1] && check(row, col - 1) && left_c > 0) {
//		if ( !visited[row][col-1] || leftvisited[row][col-1] < left_c || rightvisited[row][col+1] < right_c )
//			dfs(row, col - 1, left_c - 1, right_c);
//	}
//
//}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	int start_r, start_c;
	cin >> start_r >> start_c;
	int left_c, right_c;
	cin >> left_c >> right_c;

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			char temp; cin >> temp;
			if ( temp == '.' ) map[i][j] = 1;
			else if ( temp == '*' ) map[i][j] = 0;
		}
	}

	memset(leftvisited, 1 << 30, sizeof(leftvisited));
	memset(rightvisited, 1 << 30, sizeof(rightvisited));
	bfs(start_r, start_c, left_c, right_c);

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			if ( visited[i][j] ) ans++;
		}
	}
	cout << ans;
}