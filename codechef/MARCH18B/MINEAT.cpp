#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<limits.h>
#include<vector>
#include<stack>
#include<math.h>
#define mp make_pair
#define pb push_back
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scs(a) scanf("%s",a)
#define pii pair< long, int >
#define pr(a) printf("%d\n",a)
#define prl(a) printf("%lld ",a)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a) for(int i=a;i>=0;i--)
using namespace std;
int main() {
       int t;
       sc(t);
       while(t--)
       {
                int n,h;
                sc(n);
                sc(h);
                int a[n];
                rep(i,0,n)
                        sc(a[i]);
                int mx = *max_element(a,a+n);
                int lo = 1;
                int ho = mx;
                int ans = 0;
                while(lo <= ho)
                {
                        int mid = (lo+ho)/2;
                        int hrs = 0;
                        rep(i,0,n)
                        {
                                hrs += a[i] / mid;
                                hrs += (a[i] % mid >= 1);
                        }
                        if (hrs > h)
                                lo = mid + 1;
                        else  
                        {
                                ans = mid;
                                ho = mid - 1;
                        }
                }
                cout<<ans<<"\n";
       }
        return 0;
}
