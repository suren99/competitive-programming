#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<limits.h>
#include<vector>
#include<map>
#include<stack>
#include<math.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scs(a) scanf("%s",a)
#define pii pair<int , int >
#define pr(a) printf("%d\n",a)
#define prl(a) printf("%lld\n",a)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a) for(int i=a;i>=0;i--)
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;
bool cmp(pii a, pii b)
{
        if (a.x == b.x)
                return a.y < b.y;
        return a.x < b.x;
}
int main() {
        int n,k;
        sc(n);sc(k);
        pii a[n];
        rep(i,0,n) {
                sc(a[i].x);
                a[i].y = i;
        }
        sort(a, a+n, cmp);
        int prev = -1;
        vector<int> ans;
        rep(i,0,n)
        {
                if (prev != a[i].x) {
                        ans.pb(a[i].y + 1);
                        prev = a[i].x;
                }
        }
        if (ans.size() >= k)
        {
                printf("YES\n");
                rep(i,0,k)
                        printf("%d ",ans[i]);
        }
        else 
        {
                printf("NO\n");
        }
        return 0;
}
