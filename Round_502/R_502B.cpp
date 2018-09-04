#include <iostream>
#include <string>
using namespace std;
int cnt10, cnt00;
int cnt1, cnt0;
long long ans;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;	
	string s1, s2;
	cin >> s1; s1 = " " + s1;
	cin >> s2; s2 = " " + s2;
	for (int i = 1; i <= n; i++ )
	{
		if ( s1[i] == '0' ) cnt0++;
		else if ( s1[i] == '1' ) cnt1++;

		if ( s1[i] == '1' && s2[i] == '0' ) cnt10++;
		else if ( s1[i] == '0' && s2[i] == '0' ) cnt00++;
	}
	ans = cnt10*cnt0 + cnt00*cnt1 - cnt10*cnt00;
	cout << ans << '\n';
	cout << "cnt10 : " << cnt10 << endl;
	cout << "cnt00 : " << cnt00 << endl;
	cout << "cnt0 : " << cnt0 << endl;
	cout << "cnt1 : " << cnt1 << endl;
}