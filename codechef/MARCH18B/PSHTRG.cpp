#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<limits.h>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<math.h>
#define mp make_pair
#define pb push_back
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scs(a) scanf("%s",a)
#define pii pair<int,int >
#define pr(a) printf("%d\n",a)
#define prl(a) printf("%lld\n",a)
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a) for(int i=a;i>=0;i--)

using namespace std;
int main() {
        int n,q;
        sc(n);sc(q);          
        ll a[n];
        rep(i,0,n)
                scl(a[i]);
        rep(i,0,q)
        {
                ll type,l,r;
                multiset<ll> m;
                scl(type);
                scl(l);
                scl(r);
                l --;r--;
                if (type == 1)
                {
                        r++;
                        a[l] = r;
                        continue;
                }
                rep(j,l,r+1)
                {
                        m.insert(a[j]);
                }
                auto it = m.begin();
                ll one = 0,two = 0, three = 0;
                ll val = 0;
                while(1)
                {
                        auto next = it ;
                        if (it != m.end())
                                one = *it;
                        else 
                                break;
                        it++;
                        next = it;
                        if (it != m.end())
                                two = *it;
                        else 
                                break;
                        it++;
                        if (it != m.end())
                                three = *it;
                        else 
                                break;
                        if ((one + two) > three)
                                val = max(val, one + two + three);
                        it = next;
                }
                prl(val);
        }
        return 0;
}
