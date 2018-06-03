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
#define prl(a) printf("%lld\n",a)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a) for(int i=a;i>=0;i--)
#define ll long long
using namespace std;
const int maxn = 1e5;
int segt[20 * maxn];
int main() {
       int t;
       sc(t);
       while(t--)
       {
               int n;
               sc(n);
               ll s[n];
               rep(i,0,n)
                       scl(s[i]);
               ll pre[n];
               int pans[n + 5];
               int sans[n + 5];
               memset(pans,0,sizeof(pans));
               memset(sans,0,sizeof(sans));
               memset(pre,0,sizeof(pre));
               pre[0] = s[0];
               rep(i,1,n)
                       pre[i] = pre[i-1] + s[i];
               rep(i,0,n)
               {
                       int lo = i + 1;
                       int ho = n - 1;
                       int res;
                       if (i == n-1)
                               goto second;
                       while(lo <= ho)
                       {
                               int mid = (lo+ho)/2;
                               long long now = pre[mid-1] - pre[i];
                               if(s[i] >= now)
                               {
                                       res = mid;
                                       lo = mid + 1;
                               }
                               else 
                                       ho = mid - 1;
                       }
                       pans[i+1] += 1;
                       pans[res + 1] -= 1;
second:
                       lo = 0;
                       ho = i-1;
                       if (i==0)
                               goto end;
                       while(lo<=ho)
                       {
                                int mid = (lo+ho)/2;
                                long long now = pre[i-1] - pre[mid];
                                if(s[i] >= now)
                                {
                                        res = mid;
                                        ho = mid-1;
                                }
                                else 
                                        lo = mid + 1;
                       }
                       sans[res - 1] -= 1;
                       sans[i-1] += 1;
end:
                       ;
               }
               rev(i,n-2)
                       sans[i] += sans[i+1];
               rep(i,1,n)
                       pans[i] += pans[i-1];
               rep(i,0,n)
                       cout<<pans[i] + sans[i]<<" ";
               cout<<"\n";
       }
        return 0;
}
