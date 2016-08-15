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
  if (l == r)
    return l;
  int mid = (l + r) / 2;
  int count = u->left->cnt - v->left->cnt;
  if (count >= k)
    return query(u->left, v->left, l, mid, k);
  else
    return query(u->right, v->right, mid + 1, r, k - count);
}
node *null = new node(0, NULL, NULL);
int main() {
  ios::sync_with_stdio(false);
  std::cin >> n >> q;
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
    std::cout << m1[ans] << "\n";
  }
  return 0;
}
