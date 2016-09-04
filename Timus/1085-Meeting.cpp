#include <iostream>
#include <map>
#include <climits>
#include <cstring>
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
#define inf INT_MAX
#define y second
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define rrep(i,a,b) for(int i=a; i>=b; i--)
using namespace std;
vector<pii> v[150];
int main()
{
        ios::sync_with_stdio(false);
        int n,m;
        std::cin >> n>>m;
        rep(i,0,m-1)
        {
                int l;
                std::cin >> l;
                int prev;
                std::cin >> prev;
                rep(j,0,l-2)
                {
                        int x;
                        std::cin>> x;
                        v[prev].pb({x,i});
                        v[x].pb({prev,i});
                        prev=x;
                }
        }
        int k;
        std::cin >> k;
        int tot[150];
        int start;
        int pay[150];
        int visit[150][150];
        memset(visit,-1,sizeof(visit));
        queue<vector<int> > q;
        rep(i,0,k-1)
        {
                std::cin >> tot[i];
                std::cin >> start;
                std::cin >> pay[i];
                q.push({start,i,0,-1});
                visit[i][start]=0;
        }
        while(!q.empty())
        {
                int node=q.front()[0];
                int ppl=q.front()[1];
                int cost=q.front()[2];
                int route=q.front()[3];
                q.pop();
                for(auto it :v[node])
                {
                        int amt=(it.y!=route)  ? 4 : 0;
                        if(pay[ppl]==1)
                                amt=0;
                        if(visit[ppl][it.x]==-1)
                        {
                                visit[ppl][it.x]=cost+amt;
                                q.push({it.x,ppl,cost+amt,it.y});
                        }
                }
        }
        int stop=0;
        int ans=INT_MAX;
        rep(i,1,n)
        {
                int cost=0;
                rep(j,0,k-1)
                {
                        if(visit[j][i]>tot[j] or visit[j][i]==-1)
                        {
                                cost=inf;
                                break;
                        }
                        else
                        {
                                cost+=visit[j][i];
                        }
                }
                if(cost<ans)
                {
                        stop=i;
                        ans=cost;
                }
        }
        if(ans==inf)
                std::cout << "0" << std::endl;
        else
                std::cout << stop<<" "<<ans << std::endl;
        return 0;
}
