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
#define rev(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn = 1e5;
int segt[20 * maxn][32];
int a[maxn];
int op[32];
void  build(int ss, int se, int idx)
{
        if(ss==se)
        {
                rep(i,0,31)
                {
                        segt[idx][i] = ((a[ss] & (1<<i)) > 0);
                }
                return;
        }
        int mid = (ss+se)/2;
        build(ss,mid,2*idx+1);
        build(mid+1,se,2*idx+2);
        rep(i,0,31)
                segt[idx][i] = segt[2*idx+1][i] + segt[2*idx+2][i];
}

void query(int ss, int se, int qs, int qe, int idx)
{
        if(ss > qe or qs > se)
                return;
        if(ss >=qs and  se <= qe)
        {
                rep(i,0,31)
                        op[i] += segt[idx][i];
                return;
        }
        int mid = (ss+se)/2;
        query(ss,mid,qs,qe,2*idx+1);
        query(mid+1,se,qs,qe,2*idx+2);
}
int main() {
       int n,q;
       sc(n);sc(q);
       rep(i,0,n)
               sc(a[i]);
       memset(segt,0,sizeof(segt));
       build(0,n-1,0);
       while(q--)
       {
               int l,r;
               sc(l);sc(r);
               l--;
               r--;
               memset(op,0,sizeof(op));
               query(0,n-1,l,r,0);
               int sz = r - l + 1;
               int x = 0;
               rep(i,0,31)
               {
                        int zero = sz - op[i];
                        if (zero > op[i])
                                x += (1<<i);
               }
               pr(x);
       }
        return 0;
}
