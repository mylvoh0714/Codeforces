#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[100001];
int visited[100001];
int r[100001];
int ans = 0;

int dfs(int root)
{
	visited[root] = 1;
	for ( int i = 0; i < adj[root].size(); i++ )
	{
		int there = adj[root][i];
		if ( visited[there] ) continue;
		r[root] += dfs(there);
	}
	r[root] += 1;
	return r[root];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	if ( n % 2 == 1 ) {
		cout << -1 << '\n';
		return 0;
	}

	for ( int i = 0; i < n - 1; i++ )
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for ( int i = 1; i <= n; i++ )
	{
		if ( r[i] % 2 == 0 ) ans++;
	}
	cout << ans-1 << '\n';
}
