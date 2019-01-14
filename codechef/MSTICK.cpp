#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<limits.h>
#include<vector>
#include<map>
#include<stack>
#include<math.h>
#include<iomanip>
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
pair<int,int> mx[maxn][25], mi[maxn][25];
int n;
pair<int,int> find_max(int l, int r)
{
    int ra = log2(r - l + 1);
    return max(mx[l][ra], mx[r - (1 << ra) + 1][ra]);
}
pair<int,int> find_min(int l, int r)
{
   int ra = log2(r - l + 1);
   return min(mi[l][ra], mi[r - (1 << ra) + 1][ra]);
}
bool ok(int x, int y) {
    if (x < 0 and x >= n)
        return false;
    if (y < 0 and y >= n)
        return false;
    if (x > y) 
        return false;
    return true;  
}

int main()
{
    cin>>n;
    int a[n];
    rep(i,0,n)cin>>a[i];
    for(int i = 0; i < n; i++) {
        mx[i][0].x = a[i];
        mi[i][0].x = a[i];
        mi[i][0].y = i;
        mx[i][0].y = i;
    }
    /* build the table */
    cout<<"\n";
    for (int j = 1; j <= 25; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            mx[i][j] = max(mx[i][j-1], mx[i + (1 << (j-1))][j-1]);
            mi[i][j] = min(mi[i][j-1], mi[i + (1 << (j-1))][j-1]);
        }
    }
    int q;
    cin>>q;
    while (q--) {
        int l, r;
        cin>>l>>r;
        int mx = 0;
        double res = 0.0;
        if (ok(0,l-1))  mx = find_max(0, l-1).x;
        if (ok(r+1, n-1)) mx = max(mx, find_max(r+1, n-1).x);
        pair<int,int> mi = find_min(l,r);
        res = mi.x + mx;
        int tmp;
        std::cout << std::fixed << std::setprecision(1);
        if (ok(l,mi.y-1)) {
            tmp = find_max(l,mi.y-1).x;
            tmp -= mi.x;
            res = max(res, (double)mi.x + (double)tmp/2.0);
        }
        if (ok(mi.y+1, r)) {
            tmp = find_max(mi.y+1,r).x;
            tmp -= mi.x;
            res = max(res, (double)mi.x + (double)tmp/2.0);
        }
        cout<<res<<"\n";
    }
    return 0;
}