#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mk make_pair
#define x first
#define y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define inf (ll)1e18
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
const ll mod = (ll)1e9 + 7;
const int maxn = 5e5 + 5;
int n, q;
vector<pii> v[maxn];
int start[maxn];
int ed[maxn];
int st = 0;
int order[maxn];
ll len[maxn];
struct node {
  int cnt;
  node *left, *right;
  node(int cnt, node *left, node *right) : cnt(cnt), left(left), right(right) {}
  node *insert(int l, int r, int w);
};
node *node::insert(int l, int r, int w) {
  if (w >= l and w <= r) {
    if (l == r)
      return new node(this->cnt + 1, NULL, NULL);
    int mid = (l + r) >> 1;
    return new node(this->cnt + 1, this->left->insert(l, mid, w),
                    this->right->insert(mid + 1, r, w));
  }
  return this;
}
node *null = new node(0, NULL, NULL);
int query(node *u, node *v, int l, int r, int k) {
  if (l == r) {
    if (k > (u->cnt - v->cnt))
      return -1;
    return l;
  }
  int mid = (l + r) >> 1;
  int count = u->left->cnt - v->left->cnt;
  if (count >= k)
    return query(u->left, v->left, l, mid, k);
  return query(u->right, v->right, mid + 1, r, k - count);
}
void dfs(int node, int par, ll length) {
  start[node] = ++st;
  len[st] = length;
  rep(i, 0, (int)v[node].size() - 1) {
    int u = v[node][i].x;
    int w = v[node][i].y;
    if (u != par)
      dfs(u, node, length + (ll)w);
  }
  ed[node] = st;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin >> n;
  rep(i, 0, n - 2) {
    int u, u1, wi;
    std::cin >> u >> u1 >> wi;
    v[u].pb({u1, wi});
    v[u1].pb({u, wi});
  }
  dfs(1, -1, 0);
  null->left = null->right = null;
  node *root[n + 1];
  root[0] = null;
  int mx = 1;
  map<ll, int> m;
  map<int, ll> m1;
  rep(i, 1, n) m[len[i]];
  for (map<ll, int>::iterator it = m.begin(); it != m.end(); it++) {
    m[it->first] = mx;
    m1[mx++] = it->first;
  }
  mx--;
  rep(i, 1, n) { root[i] = root[i - 1]->insert(1, mx, m[len[i]]); }
  std::cin >> q;
  while (q--) {
    int vertex, k;
    std::cin >> vertex >> k;
    int l = start[vertex];
    int r = ed[vertex];
    int ans = query(root[r], root[l], 1, mx, k);
    if (ans == -1)
      std::cout << ans << "\n";
    else
      std::cout << m1[ans] - len[l] << "\n";
  }
  return 0;
}
