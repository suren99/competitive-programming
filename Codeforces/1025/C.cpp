/* look closely it boils down to find the max zebra in a cyclic string */

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<limits.h>
#include<vector>
#include<limits>
#include<map>
#include<stack>
#include<unordered_map>
#include<math.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scs(a) cin>>s;
#define pii pair<int , int >
#define pr(a) printf("%d\n",a)
#define prl(a) printf("%lld\n",a)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;

int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int n = (int)s.size();
    string scap = s + s;
    int res = 0;
    int ans = 0;
    rep(i,1,2 * n-2)
    {
        if (scap[i]!= scap[i-1])
            ans++;
        else
        {
            res = max(ans + 1, res);
            ans = 0;
        }
    }
    res = max(ans + 1, res);
    cout << min(res,n);
    return 0;
}

