#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
vector< vector<int> > adj;
int visited[300001];
long long cnt;
int n, x, y;

long long dfs(int r)
{
	stack<int> st;
	memset(visited, 0, sizeof(visited));
	cnt = 0;

	st.push(r);
	while ( !st.empty() )
	{
		int here = st.top();
		st.pop();
		visited[here] = 1;
		for ( int i = 0; i < adj[here].size(); i++ )
		{
			int there = adj[here][i];
			
			if ( visited[there] ) continue;
			if ( visited[x] && there == y ) continue;
			st.push(there);
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	cin >> n >> x >> y;
	adj.resize(n + 1);
	
	for ( int i = 0; i < n - 1; i++ )
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	long long ans = 0;
	for ( int i = 1; i <= n; i++ )
	{
		ans += dfs(i);
	}
	cout << ans << '\n';
}
