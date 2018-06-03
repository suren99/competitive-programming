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
#define pr(a) printf("%d ",a)
#define prl(a) printf("%lld ",a)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a) for(i=a;i>=0;i--)
using namespace std;
int main() {
        int t;
        cin>>t;
        while(t--)
        {
                int n;
                cin>>n;
                long double loss = 0.0;
                while(n--)
                {
                        int p,q,d;
                        cin>>p>>q>>d;
                        long double ans = 0.0;
                        ans = (long double)(p + 0.0) + (long double) p * (long double)(d/100.0); //increase
                        ans = ans - (long double) ans * (long double) (d/100.0); //decrease
                        loss += (long double) q  * (p - ans);
                }
                printf("%Lf\n",loss);
        }
        return 0;
}
