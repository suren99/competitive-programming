#include<iostream>
#include<map>
#include<climits>
#include<unordered_map>
#include<utility>
#include<vector>
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
const int maxn=3e4+5;
struct qu
{
    int a,b,c;
};
int segt[maxn];
int lazy[maxn];
int ans;
vector<int> mark;
vector<qu> q;
map<int,int> m,rm;
void update(int ss,int se,int qs,int qe,int idx,int val)
{
    if(lazy[idx]!=-1)
    {
        segt[idx]=lazy[idx];
        if(ss!=se)
        {
            lazy[2*idx+1]=segt[idx];
            lazy[2*idx+2]=segt[idx];
        }
        lazy[idx]=-1;
    }
    if(ss>qe or se<qs)return;
    if(ss>=qs and se<=qe)
    {
        segt[idx]=val;
        if(ss!=se)
        {
            lazy[2*idx+1]=val;
            lazy[2*idx+2]=val;
        }
        return;
    }
    int mid=(ss+se)/2;
    update(ss,mid,qs,qe,2*idx+1,val);
    update(mid+1,se,qs,qe,2*idx+2,val);
}
void query(int ss,int se,int qs,int idx)
{
    if(lazy[idx]!=-1)
    {
        segt[idx]=lazy[idx];
        if(ss!=se)
        {
            lazy[2*idx+1]=segt[idx];
            lazy[2*idx+2]=segt[idx];
        }
        lazy[idx]=-1;
    }
    if(ss>qs or se<qs)
    return;
    if(ss==se)
    {
        ans=segt[idx];
        return;
    }
    int mid=(ss+se)/2;
    query(ss,mid,qs,2*idx+1);
    query(mid+1,se,qs,2*idx+2);
}
int main()
{
   ios::sync_with_stdio(false);
   int n;
   std::cin >> n;
   rep(i,0,n-1)
   {
       int l,r;
       char w;
       std::cin >> l>>r>>w;
       q.pb({l,r,w=='b'});
       m[l];
       m[r];
   }
   int cnt=0;
   rm[cnt++]=0;
   for(auto it=m.begin();it!=m.end();it++)
       rm[cnt++]=it->first;
   rm[cnt++]=1e9;
   mark.resize(cnt+5);
   rep(i,0,n-1)
       update(0,cnt,rm[q[i].a],rm[q[i].b]-1,0,q[i].c);
   rep(i,0,cnt-1)
   {
      query(0,cnt,i,0);
      mark[i]=ans;
  }
  int ans=0,ansl=0,ansr=1;
  int i=0;
  int j=0;
  rep(i,0,cnt-2)
  {
      if(mark[i]==1)continue;
      j=max(i+1,j);
      while(j<cnt-1 and mark[j]==0)j++;
      if((rm[j]-rm[i])>ans)
      {
          ans=rm[j]-rm[i];
          ansl=rm[i];
          ansr=rm[j];
      }
  }
  std::cout << ansl<<" "<<ansr << "\n";
  return 0;
}
