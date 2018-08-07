By mylvoh0714, contest: Codeforces Round #496 (Div. 3), problem: (D) Polycarp and Div 3, Accepted, #
 #include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int dp[200001][4]; // dp[length][sum]
string str;

int solve(int pos, int sum)
{
	if(pos == str.size()) {
		return 0;
	}
	int &ret = dp[pos][sum];
	if(ret>0)
		return ret;
	sum+=str[pos];
	if(sum%3 == 0) {
		return ret = 1+solve(pos+1,0);
	} else {
		return ret = max(solve(pos+1,0),solve(pos+1,sum%3));
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> str;
	int len = str.size();
	cout << solve(0,0) << '\n';
}
