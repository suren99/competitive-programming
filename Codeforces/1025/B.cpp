/* Its sufficient to find the prime factors for first pair and check if all 2 *log n (in worst case) factors makes
a mark in other pairs */

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

vector<int> factors(int a)
{
        vector<int> op;
        int b = a;

        if(a%2 == 0)
        {
                op.push_back(2);
                while(a%2 == 0) a/=2;
        }
        for(int i = 3; i * i <= b ;i++)
        {
              if(a%i == 0)
                {
                        op.push_back(i);
                        while(a%i == 0) a/=i;
                }   
        }
        if (a != 1)
        op.push_back(a);
        return op;
}

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin>>n;
        vector<int> divider, t;
        int a[n], b[n];
        rep(i,0,n-1)
        {
                cin>>a[i]>>b[i];
        }
        divider = factors(a[0]);
        t = factors(b[0]);
        divider.insert(divider.end(),t.begin(),t.end());
        int mark[(int)divider.size()];
        memset(mark, 0, sizeof(mark));
        rep(i,1,n-1)
        {
                rep(j,0,(int)divider.size()-1)
                {
                        if (a[i] % divider[j] != 0 and b[i] % divider[j] != 0)
                                mark[j] = 1;
                }
        }
        rep(i,0,(int)divider.size()-1)
        {
                if(mark[i] == 0)
                {
                        cout<<divider[i]<<"\n";
                        return 0;
                }
        }
        cout<<"-1";
        return 0;
}
