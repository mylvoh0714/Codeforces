#include <bits/stdc++.h>
using namespace std;
int p[300001];

int Find(int x) {
	if ( x == p[x] ) {
		return x;
	}
	else {
		return p[x] = Find(p[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	p[x] = y;
}

struct Edge {
	int x;
	int y;
	int w;
	int number;
};

bool operator<(Edge &e1, Edge &e2)
{
	return e1.w < e2.w;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<Edge> a(m);
	for ( int i = 1; i <= n; i++ ) p[i] = i;
	for ( int i = 0; i < m; i++ )
	{
		cin >> a[i].x >> a[i].y >> a[i].w;
		a[i].number = i + 1;
	}
	sort(a.begin(), a.end());
	vector<int> ans;
	for ( int i = 0; i < m; i++ )
	{
		Edge e = a[i];
		int x = Find(e.x);
		int y = Find(e.y);
		if ( x != y ) {
			Union(e.x, e.y);
			ans.push_back(e.number);
		}
		if ( ans.size() >= k ) break;
	}
	cout << ans.size() << '\n';
	for ( int &i : ans ) cout << i << ' ';

}