#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,a,b;
    cin >> n >> a >> b;
    int less_cost = min(a,b);
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin >> arr[i];

    int ans = 0;
    if(n%2 == 1 ) {
        int idx = n/2 + 1;
        if(arr[idx]==2) ans += less_cost;
    }
    for(int i=1;i<=n/2;i++)
    {
        if(arr[i]==0 && arr[n+1-i]==0) continue;
        else if(arr[i]==1 && arr[n+1-i]==1) continue;
        else if(arr[i] == 0 && arr[n+1-i] == 1) {
            ans = -1;
            break;
        }
        else if(arr[i] == 1 && arr[n+1-i] == 0) {
            ans = -1;
            break;
        }
        else if(arr[i]==2 && arr[n+1-i]==2) {
            ans += less_cost*2;
        }
        else if((arr[i]==2 && arr[n+1-i]==0) || (arr[i] == 0 && arr[n+1-i]==2)) {
            ans += a;
        }
        else if((arr[i]==2 && arr[n+1-i]==1) || (arr[i]==1 && arr[n+1-i] ==2)) {
            ans += b;
        }
    }
    cout << ans << '\n';
}
