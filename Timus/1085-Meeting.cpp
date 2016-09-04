#include <iostream>
#include <map>
#include <climits>
#include <unordered_map>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define x first
#define y second
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define rrep(i,a,b) for(int i=a; i>=b; i--)
using namespace std;
vector<int> v[100];
int subnet[100][100][4];
int sz[100];
int k,n;
vector<int> decode(int i,string s1)
{
        int no=0;
        vector<int> a;
        rep(j,0,(int)s1.size()-1)
        {
                if(s1[j]=='.')
                {
                        a.pb(no);
                        no=0;
                }
                else
                        no=no*10+(s1[j]-'0');
        }
        a.pb(no);
        return a;
}
int main()
{
        ios::sync_with_stdio(false);
        std::cin >> n;
        rep(i,0,n-1)
        {
                std::cin >> k;
                sz[i]=k;
                rep(l,0,k-1)
                {
                        string s1,s2;
                        std::cin >> s1>>s2;
                        vector<int> c=decode(i,s1);
                        vector<int> d=decode(i,s2);
                        rep(j,0,3)
                        {
                                subnet[i][l][j]=c[j]&d[j];
                        }
                }
        }
        int src,dest;
        std::cin >> src>>dest;
        rep(i,0,n-1)
        {
                rep(j,0,n-1)
                {
                        rep(g,0,sz[i]-1)
                        {
                                rep(h,0,sz[j]-1)
                                {
                                        int fl=1;
                                        rep(r,0,3)
                                        {
                                                if(subnet[i][g][r]!=subnet[j][h][r])
                                                        fl=0;
                                        }
                                        if(fl)
                                                v[i].pb(j);
                                }
                        }
                }
        }
        queue<pair<int,vector<int> > > q;
        int visit[100]={0};
        rep(i,0,sz[src-1]-1)
        {
                q.push({src-1,{src-1}});
        }
        while(!q.empty())
        {
                vector<int> path=q.front().y;
                int last=q.front().x;
                visit[last]=1;
                if(last==dest-1)
                {
                        std::cout << "Yes" << "\n";
                        rep(i,0,path.size()-1)
                        {
                                std::cout << path[i]+1<<" ";
                        }
                        return 0;
                }
                q.pop();
                rep(i,0,v[last].size()-1)
                {
                        int node=v[last][i];
                        if(!visit[node])
                        {
                                vector<int> temp=path;
                                temp.pb(node);
                                q.push({node,temp});
                        }
                }
        }
        std::cout << "No" << "\n";
        return 0;
}
