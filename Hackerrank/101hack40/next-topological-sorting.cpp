#include <bits/stdc++.h>
#define ll long long
#define mk make_pair
#define pb push_back
#define x first
#define y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define inf (ll)1e18
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
const int maxn = 1e5 + 5;
int indegree[maxn];
vector<int> a[maxn];
int p[maxn];
int tmp[maxn];
int n, m;
void reduce(int now, set<int> &s, int *deg) {
  s.erase(now);
  for (auto i : a[now]) {
    deg[i]--;
    if (!deg[i])
      s.insert(i);
  }
}
int ok(int p_end) {
  set<int> s;
  memcpy(tmp, indegree, sizeof(indegree));
  rep(i, 1, n) {
    if (!tmp[i])
      s.insert(i);
  }
  rep(i, 1, p_end) { reduce(p[i], s, tmp); }
  int cnt = 1;
  while (!s.empty()) {
    int el = *s.rbegin();
    if (el > p[cnt + p_end])
      return true;
    reduce(el, s, tmp);
    cnt++;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin >> n >> m;
  memset(indegree, 0, sizeof(indegree));
  rep(i, 0, m - 1) {
    int u, v;
    std::cin >> u >> v;
    a[u].pb(v);
    indegree[v]++;
  }
  rep(i, 1, n) std::cin >> p[i];
  int lo = 0;
  int ho = n - 1;
  int steps = -1;
  while (lo <= ho) {
    int mid = (lo + ho) / 2;
    if (ok(mid)) {
      steps = mid;
      lo = mid + 1;
    } else
      ho = mid - 1;
  }
  if (steps == -1)
    std::cout << -1 << "\n";
  else {
    set<int> s;
    rep(i, 1, n) {
      if (!indegree[i])
        s.insert(i);
    }
    rep(i, 1, steps) {
      reduce(p[i], s, indegree);
      std::cout << p[i] << " ";
    }
    steps++;
    int st = steps;
    while (!s.empty()) {
      if (st == steps) {
        auto it = s.upper_bound(p[st]);
        std::cout << *it << " ";
        reduce(*it, s, indegree);
      } else {
        std::cout << *s.begin() << " ";
        reduce(*s.begin(), s, indegree);
      }
      st++;
    }
  }
  return 0;
}
