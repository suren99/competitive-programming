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
vector<ll> a;
int n;
ll s;
int main() {
  ios::sync_with_stdio(false);
  std::cin >> n >> s;
  a.resize(n);
  rep(i, 0, n - 1) std::cin >> a[i];
  if (n == 1) {
    std::cout << 0 << "\n";
    return 0;
  }
  sort(a.begin(), a.end());
  int idx = -1;
  rep(i, 0, n - 1) {
    if (a[i] <= s)
      idx = i;
  }
  ll f[n];
  ll b[n];
  int sz1 = 0;
  int sz2 = 0;
  int fl1 = 0;
  int fl2 = 0;
  if (idx >= 0) {
    f[sz1++] = abs(s - a[idx]);
    rrep(i, idx - 1, 0) {
      f[sz1] = abs(a[i + 1] - a[i]) + f[sz1 - 1];
      sz1++;
    }
    fl1 = 1;
  }
  if (idx < n - 1) {
    b[sz2++] = abs(a[idx + 1] - s);
    rep(i, idx + 2, n - 1) {
      b[sz2] = abs(a[i] - a[i - 1]) + b[sz2 - 1];
      sz2++;
    }
    fl2 = 1;
  }
  ll ans = LLONG_MAX;
  if (fl1 == 0)
    ans = b[n - 2];
  else if (fl2 == 0)
    ans = f[n - 2];
  else {
    ll el1 = 0, el2 = 0;
    if (sz1 - 2 >= 0)
      el1 = f[sz1 - 2];
    if (sz2 - 2 >= 0)
      el2 = b[sz2 - 2];
    ans = min(ans, 2LL * el1 + b[sz2 - 1]);
    ans = min(ans, 2LL * f[sz1 - 1] + el2);
    ans = min(ans, f[sz1 - 1] + 2LL * el2);
    ans = min(ans, el1 + 2LL * b[sz2 - 1]);
  }
  std::cout << ans << "\n";
  return 0;
}
