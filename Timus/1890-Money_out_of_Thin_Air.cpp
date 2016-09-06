#include<iostream>
#include<map>
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
const int maxn=5e4+5;
int n,q;
vector<int> v[maxn];
int st[maxn];
int ed[maxn];
ll s[maxn];
int tour[maxn];
ll segt[40*maxn];
ll lazy[40*maxn];
int cnt=-1;
void dfs(int node)//dfs-order
{
    st[node]=++cnt;
    tour[cnt]=node;
    for (int i = 0; i <(int) v[node].size(); ++i)
    {
        dfs(v[node][i]);
    }
    ed[node]=cnt;
}
void build(int ss,int se,int idx)
{
    if(ss==se)
    {
        segt[idx]=s[tour[ss]];
        return;
    }
    int mid=(ss+se)/2;
    build(ss,mid,2*idx+1);
    build(mid+1,se,2*idx+2);
    segt[idx]=segt[2*idx+1]+segt[2*idx+2];
}
ll query(int ss,int se,int qs,int qe,int idx)
{
    if(lazy[idx]!=0)
    {
        segt[idx]+=(se-ss+1)*lazy[idx];
        if(ss!=se)
        {
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(ss>qe or se<qs)
    return 0;
    if(ss>=qs and se<=qe)
    return segt[idx];
    int mid=(ss+se)/2;
    return query(ss,mid,qs,qe,2*idx+1)+query(mid+1,se,qs,qe,2*idx+2);
}
void update(int ss,int se,int qs,int qe,int idx,ll val)
{
    if(lazy[idx]!=0)
    {
        segt[idx]+=(se-ss+1)*lazy[idx];
        if(ss!=se)
        {
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(ss>qe or se<qs)
    return;
    if(ss>=qs and se<=qe)
    {
        segt[idx]+=(se-ss+1)*val;
        if(ss!=se)
        {
            lazy[2*idx+1]+=val;
            lazy[2*idx+2]+=val;
        }
        return;
    }
    int mid=(ss+se)/2;
    update(ss,mid,qs,qe,2*idx+1,val);
    update(mid+1,se,qs,qe,2*idx+2,val);
    segt[idx]=segt[2*idx+1]+segt[2*idx+2];
}
int main()
{
   ios::sync_with_stdio(false);
   std::cin >> n>>q>>s[0];
   rep(i,0,n-2)
   {
       int x;
       ll y;
       std::cin >> x>>y;
       v[x].pb(i+1);
       s[i+1]=y;
   }
   dfs(0);//convert tree into array
   build(0,n-1,0);
   while(q--)
   {
       string ss;
       int x;
       ll y,z;
       std::cin >>ss>> x>>y>>z;
       if(ss[0]=='e')
       {
            ll current_salary=query(0,n-1,st[x],st[x],0);
            if(current_salary<y)
            {
                update(0,n-1,st[x],st[x],0,z);
            }
       }
       else
       {
           ll tot=query(0,n-1,st[x],ed[x],0); //sum of salaries of all employees in department x;
           ll no_of_employees=ed[x]-st[x]+1;
           if(tot <(y*no_of_employees))//check if average salary is less than y
           {
               update(0,n-1,st[x],ed[x],0,z);
           }
       }
   }
   rep(i,0,n-1)
   {
       std::cout << query(0,n-1,st[i],st[i],0) << "\n";
   }
   return 0;
}
