// Author-suren99
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
const ll mod = (ll)1e9 + 7;
const int maxn = 2e5 + 5;
int n;
int a[maxn], q;
int cur;
ll fact[maxn];
ll inv[maxn];
struct node {
  int cnt;
  node *left, *right;
  node(int cnt, node *left, node *right) : cnt(cnt), left(left), right(right) {}
  node *insert(int l, int r, int w);
};
node *root[maxn];
node *node::insert(int l, int r, int w) {
  if (w >= l and w <= r) {
    if (l == r) {
      return new node(this->cnt + 1, NULL, NULL);
    }
    int mid = (l + r) / 2;
    return new node(this->cnt + 1, this->left->insert(l, mid, w),
                    this->right->insert(mid + 1, r, w));
  }
  return this;
}
int query(node *u, node *v, int l, int r, int k) {
  if (l == r) {
    cur = k;
    return l;
  }
  int mid = (l + r) / 2;
  int count = u->left->cnt - v->left->cnt;
  if (count >= k)
    return query(u->left, v->left, l, mid, k);
  else
    return query(u->right, v->right, mid + 1, r, k - count);
}
int query1(node *u, node *v, int l, int r, int qs, int qe) {
  if (qs > qe)
    return 0;
  if (l > qe or r < qs) {
    return 0;
  }
  if (l >= qs and r <= qe) {
    return u->cnt - v->cnt;
  }
  int mid = (l + r) / 2;
  return query1(u->left, v->left, l, mid, qs, qe) +
         query1(u->right, v->right, mid + 1, r, qs, qe);
}
node *null = new node(0, NULL, NULL);
ll mdpw(ll base, ll pw) {
  ll ans = 1;
  while (pw != 0) {
    if (pw & 1)
      ans = (ans * base) % mod;
    base = (base * base) % mod;
    pw /= 2;
  }
  return ans;
}
ll C(int m, int r) {
  if (r <= 0 || r > m)
    return 0;
  ll ans = fact[m];
  ans = (ans * inv[m - r]) % mod;
  ans = (ans * inv[r]) % mod;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin >> n >> q;
  fact[0] = 1;
  rep(i, 1, n) fact[i] = (i * fact[i - 1]) % mod;
  inv[n] = mdpw(fact[n], mod - 2);
  rrep(i, n - 1, 0) inv[i] = ((i + 1) * inv[i + 1]) % mod;
  map<int, int> m, m1;
  rep(i, 1, n) {
    std::cin >> a[i];
    m[a[i]] = 1;
  }
  int mx = 0;
  for (auto it = m.begin(); it != m.end(); it++) {
    m[it->first] = mx;
    m1[mx] = it->first;
    mx++;
  }
  mx--;
  null->left = null;
  null->right = null;
  root[0] = null;
  rep(i, 1, n) { root[i] = root[i - 1]->insert(0, mx, m[a[i]]); }
  while (q--) {
    int u, v, k;
    std::cin >> u >> v >> k;
    int ans = query(root[v], root[u - 1], 0, mx, k);
    int less = query1(root[v], root[u - 1], 0, mx, 0, ans - 1);
    int le = query1(root[v], root[u - 1], 0, mx, 0, ans);
    int idx = less + cur;
    int m = le - less;
    int r = idx - less;
    std::cout << C(m, r) << "\n";
  }
  return 0;
}
