#include<iostream>
#include<stdio.h>
#include<map>
#include <iomanip>
#include<climits>
#include<utility>
#include<vector>
#include<cstring>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define x first
#define y second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn=1e6+1;
int bit[maxn];
void update(int idx,int val)
{
    for(int i=idx;i>0;i-=i & -i)
    {
        bit[i]+=val;
    }
}
int query(int idx)
{
    int ans=0;
    for(int i=idx;i<maxn;i+=i & -i)
    {
        ans+=bit[i];
    }
    return ans;
}
int main()
{
   ll res=0;
   while (true)
   {
       char s[50];
       scanf("%s",s);
       if(s[0]=='B')
       {
           float x;
           scanf("%f",&x);
           update((int)(x*100.0+0.1),1);
       }
       else if(s[0]=='S')
       {
           float x;
           int k;
           scanf("%f",&x);
           scanf("%d",&k);
           res+=min(k,query((int)(x*100.0+0.1)));
       }
       else if(s[0]=='D')
       {
           float x;
           scanf("%f",&x);
           update((int)(x*100.0+0.1),-1);
       }
       else break;
   }
   printf("%.2f\n",res/100.0);
   return 0;
}
