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
#define prs(a) printf("%s\n",a)
#define prl(a) printf("%lld\n",a)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a) for(int i=a;i>=0;i--)
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;

bool cmp(string a, string b)
{
        return a.size() < b.size();
}
int main()
{
        int n;
        sc(n);
        vector<string> v(n);
        rep(i,0,n)
                cin>>v[i];
        int ok = 1;
        sort(v.begin(),v.end(),cmp);
        rep(i,1,n) { 
                 if (v[i].find(v[i-1]) == string:: npos) {
                        ok = 0;
                        break;
                }
        }
        if (ok) {
                printf("YES\n");
                rep(i,0,n)
                        cout<<v[i]<<"\n";
        }
        else
                printf("NO\n");
}
