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
int k;
vector<int> a(maxn), b(maxn);
vector<int> bo(maxn);
int segt[maxn];
int lazy[maxn];
pii qu[maxn];
int build(int ss, int se, int idx) {
  if (ss == se)
    return segt[idx] = bo[ss];
  int mid = (ss + se) >> 1;
  return segt[idx] =
             build(ss, mid, 2 * idx + 1) + build(mid + 1, se, 2 * idx + 2);
}
int query(int ss, int se, int qs, int qe, int idx) {
  if (lazy[idx] >= 0) {
    if (lazy[idx] == 1)
      segt[idx] = se - ss + 1;
    if (lazy[idx] == 0)
      segt[idx] = 0;
    if (ss != se) {
      lazy[2 * idx + 1] = lazy[idx];
      lazy[2 * idx + 2] = lazy[idx];
    }
    lazy[idx] = -1;
  }
  if (ss > qe or se < qs)
    return 0;
  if (ss >= qs and se <= qe)
    return segt[idx];
  int mid = (ss + se) >> 1;
  return query(ss, mid, qs, qe, 2 * idx + 1) +
         query(mid + 1, se, qs, qe, 2 * idx + 2);
}
int update(int ss, int se, int qs, int qe, int idx, int fl) {
  if (lazy[idx] >= 0) {
    if (lazy[idx] == 1)
      segt[idx] = se - ss + 1;
    if (lazy[idx] == 0)
      segt[idx] = 0;
    if (ss != se) {
      lazy[2 * idx + 1] = lazy[idx];
      lazy[2 * idx + 2] = lazy[idx];
    }
    lazy[idx] = -1;
  }
  if (qs > qe)
    return 0;
  if (ss > qe or se < qs)
    return segt[idx];
  if (ss >= qs and se <= qe) {
    if (fl)
      segt[idx] = se - ss + 1;
    else
      segt[idx] = 0;
    if (ss != se) {
      lazy[2 * idx + 1] = fl;
      lazy[2 * idx + 2] = fl;
    }
    return segt[idx];
  }
  int mid = (ss + se) >> 1;
  return segt[idx] = update(ss, mid, qs, qe, 2 * idx + 1, fl) +
                     update(mid + 1, se, qs, qe, 2 * idx + 2, fl);
}
int check(int x) {
  rep(i, 0, n - 1) { bo[i] = (a[i] >= x); }
  memset(segt, 0, sizeof(segt));
  memset(lazy, -1, sizeof(lazy));
  build(0, n - 1, 0);
  rep(i, 0, q - 1) {
    int cnt = query(0, n - 1, qu[i].x, qu[i].y, 0);
    update(0, n - 1, qu[i].y - cnt + 1, qu[i].y, 0, 1);
    update(0, n - 1, qu[i].x, qu[i].y - cnt, 0, 0);
  }
  return query(0, n - 1, k, k, 0);
}
int main() {
  ios::sync_with_stdio(false);
  std::cin >> n >> q >> k;
  a.resize(n);
  b.resize(n);
  rep(i, 0, n - 1) std::cin >> a[i];
  rep(i, 0, q - 1) std::cin >> qu[i].x >> qu[i].y;
  b = a;
  sort(b.begin(), b.end());
  int lo = 0, ho = n - 1;
  int ans = -1;
  while (lo <= ho) {
    int mid = (lo + ho) >> 1;
    if (check(b[mid])) {
      ans = b[mid];
      lo = mid + 1;
    } else
      ho = mid - 1;
  }
  std::cout << ans << "\n";
  return 0;
}
