/* The trick lies in reducing n^3 states. Once you observe that the root always lies only at start2-1 or end1+1
of a left (start1,end1) and right(start2,end2) subtree,it becomes a standard dp problem. Beware of Tighter constraints. :'( */

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
const int maxn = 800;
int n;
int a[maxn];
int pgcd[maxn][maxn];
int dp[800][800][2];

int gcd(int a,int b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}

int get(int i, int j, int k)
{
    if (!k)
        return j+1;
    else
        return i-1;
}

int f(int i, int j, int k)
{
    if (i > j)
        return 1;
    int *res = &dp[i][j][k];
    if (*res != -1)
        return *res;
    if (i==j)
        return pgcd[get(i,j,k)][i] > 1;
    *res = 0;
    rep(l,i,j)
    {
        if(pgcd[get(i,j,k)][l] > 1) {
            *res = f(i,l-1,0) & f(l+1,j,1);
            if (*res)
                return 1;
        }
    }
    return *res;
}
int main()
{
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin>>n;
    rep(i,0,n-1)
    cin>>a[i];
    int res = 0;
    rep(i,0,n-1)
    {
        rep(j,0,n-1)
         pgcd[i][j] = gcd(a[i],a[j]);
    }
    rep(i,0,n-1)
    {
        res |= f(0,i-1,0) & f(i+1,n-1,1);
        if (res)
            break;
    }
    if (res)
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}

