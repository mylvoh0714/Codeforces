By mylvoh0714, contest: Codeforces Round #492 (Div. 2) [Thanks, uDebug!], problem: (E) Leaving the Bar, Wrong answer on test 79, #
 #include <iostream>
#include <vector>
#include <utility>
using namespace std;
double INF = 225*10000000000; // (1.5*10^6)ÀÇ Á¦°ö

double getDistance(double x, double y)
{
	return x*x + y*y;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector< pair<double,double> > arr(n+1);
	pair<double,double> pos;
	cin >> arr[1].first >> arr[1].second;
	pos.first = arr[1].first;
	pos.second = arr[1].second;

	int ans = 1; // 1 or -1
	if(getDistance(pos.first,pos.second) <= INF) cout << 1 << '\n';
	//cout << pos.first << ' ' << pos.second << endl;
	double x1,y1,x2,y2;
	for(int i=2;i<=n;i++)
	{
		cin >> arr[i].first >> arr[i].second;
		x1 = pos.first + arr[i].first;
		y1 = pos.second + arr[i].second;
		x2 = pos.first - arr[i].first;
		y2 = pos.second - arr[i].second;
		if(getDistance(x1,y1) < getDistance(x2,y2)) {
			pos.first = x1; pos.second = y1;
			ans = 1;
		} else {
			pos.first = x2; pos.second = y2;
			ans = -1;
		}
		cout << ans << ' ';
		cout << '\n';
		//cout << pos.first << ' ' << pos.second << endl;
		// if(getDistance(pos.first,pos.second) <= INF) cout << 1 << '\n';
		// else cout << -1 << '\n';
	}
}
