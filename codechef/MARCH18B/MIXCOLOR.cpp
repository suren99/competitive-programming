#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<limits.h>
#include<vector>
#include<stack>
#include<map>
#include<math.h>
#define x first
#define y second
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
using namespace std;
int main() {
        int t;
        sc(t);
        while(t--)
        {
                int n;
                sc(n);
                int a[n];
                map<int,int> m;
                rep(i,0,n)
                {
                        sc(a[i]);
                        m[a[i]] +=1;
                }
                int ans = 0;
                for(auto it = m.begin(); it != m.end() ; it++)
                {
                        ans += it->y - 1;
                }
                pr(ans);
        }

        return 0;
}
