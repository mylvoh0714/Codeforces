#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;

    vector<int> ansVec;
    int ans = 0;
    int pos = 0;
    int MOD = n%(2*k+1);
    if(MOD >= k+1) {
        pos = MOD;
        ansVec.push_back(pos-k);
        ans++;
        while(pos+k+1<n)
        {
            pos += k+1;
            ansVec.push_back(pos);
            ans++;
        }
    }
    else {
        pos = MOD + (2*k+1);
        int first,last;
        for(int i=k+1;i<=2*k+1;i++)
        {
            for(int j=k+1;j<=2*k+1;j++)
            {
                if(i+j == pos) {
                    first = i;
                    last = j;
                }
            }
        }
        pos -= last;
        pos -= k;
        ansVec.push_back(pos);
        ans++;
        while(pos+2*k+1<n-first)
        {
            pos += 2*k+1;
            ansVec.push_back(pos);
            ans++;
        }
        ansVec.push_back(n-last+k+1);
        ans++;
    }

    cout << ans << '\n';
    for(int i=0;i<ansVec.size();i++)
    {
        cout << ansVec[i] << ' ';
    }
}
