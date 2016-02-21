#include <bits/stdc++.h>
#define pb push_back
#define x first
#define ll long long
#define mk make_pair
#define y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define inf INT_MAX
#define rep(i, a, b) for (ll i = a; i <= b; ++i)
#define rrep(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int mul(int a, int b) {
  ll both = 1LL * a * b;
  return both % mod;
}
int add(int a, int b) { return (a + b) % mod; }
int main() {
  ios::sync_with_stdio(false);
  ll n, m;
  std::cin >> n >> m;
  vector<ll> x(n), y(n);
  ll p1[n], p2[n];
  memset(p1, 0, sizeof(n));
  memset(p2, 0, sizeof(n));
  rep(i, 0, n - 1) { std::cin >> x[i] >> y[i]; }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  p1[0] = x[0];
  p2[0] = y[0];
  rep(i, 1, n - 1) {
    p1[i] = x[i] + p1[i - 1];
    p2[i] = y[i] + p2[i - 1];
  }
  string s;
  cin >> s;
  ll curx = 0LL;
  ll cury = 0LL;
  ll cur1 = 0LL;
  ll cur2 = 0LL;
  ll ans = 0LL;
  rep(i, 0, m - 1) {
    if (s[i] == 'U') {
      cury++;
    }
    if (s[i] == 'D') {
      cury--;
    }
    if (s[i] == 'L') {
      curx--;
    }
    if (s[i] == 'R') {
      curx++;
    }
    ll cur1 = upper_bound(x.begin(), x.end(), curx) - x.begin();
    ll cur2 = upper_bound(y.begin(), y.end(), cury) - y.begin();
    cur1--;
    cur2--;
    ans = 0LL;
    if (cur1 >= 0) {
      ans += (cur1 + 1) * curx - p1[cur1];
      ans += p1[n - 1] - p1[cur1] - ((n - cur1 - 1) * curx);
    } else
      ans += p1[n - 1] - n * curx;
    if (cur2 >= 0) {
      ans += (cur2 + 1) * cury - p2[cur2];
      ans += p2[n - 1] - p2[cur2] - ((n - cur2 - 1) * cury);
    } else {
      ans += p2[n - 1] - n * cury;
    }
    std::cout << ans << "\n";
  }
  return 0;
}
