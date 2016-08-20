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
#define MOD1 50000017
#define MOD2 40000003
#define h 26
#define SZ (1 << 15)
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 5e5 + 5;
string s1;
int n, m;
string s2;
vector<pii> H[SZ];
int ok(int l) {
  rep(i, 0, SZ - 1) H[i].clear();
  int win1 = 1;
  int win2 = 1;
  rep(i, 0, l - 2) {
    win1 = (win1 * h) % MOD1;
    win2 = (win2 * h) % MOD2;
  }
  int sum1 = 0;
  int sum2 = 0;
  rep(i, 0, l - 1) {
    sum1 = (sum1 * h + s1[i]) % MOD1;
    sum2 = (sum2 * h + s1[i]) % MOD2;
  }
  H[sum1 % SZ].pb({sum1, sum2});
  rep(i, l, n - 1) {
    sum1 -= s1[i - l] * win1 % MOD1;
    sum2 -= s1[i - l] * win2 % MOD2;
    if (sum1 < 0)
      sum1 += MOD1;
    if (sum2 < 0)
      sum2 += MOD2;
    sum1 = (sum1 * h + s1[i]) % MOD1;
    sum2 = (sum2 * h + s1[i]) % MOD2;
    H[sum1 % SZ].pb({sum1, sum2});
  }
  sum1 = 0;
  sum2 = 0;
  rep(i, 0, l - 1) {
    sum1 = (sum1 * h + s2[i]) % MOD1;
    sum2 = (sum2 * h + s2[i]) % MOD2;
  }
  rep(i, 0, (int)H[sum1 % SZ].size() - 1) {
    if (H[sum1 % SZ][i].x == sum1 and H[sum1 % SZ][i].y == sum2) {
      return 0;
    }
  }
  rep(i, l, m - 1) {
    sum1 -= s2[i - l] * win1 % MOD1;
    sum2 -= s2[i - l] * win2 % MOD2;
    if (sum1 < 0)
      sum1 += MOD1;
    if (sum2 < 0)
      sum2 += MOD2;
    sum1 = (sum1 * h + s2[i]) % MOD1;
    sum2 = (sum2 * h + s2[i]) % MOD2;
    rep(j, 0, (int)H[sum1 % SZ].size() - 1) {
      if (H[sum1 % SZ][j].x == sum1 and H[sum1 % SZ][j].y == sum2) {
        return i - l + 1;
      }
    }
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin >> s1 >> s2;
  n = (int)s1.size();
  m = (int)s2.size();
  rep(i, 0, n - 1) s1[i] -= 'a';
  rep(i, 0, m - 1) s2[i] -= 'a';
  int lo = 1;
  int ho = m;
  int sz = 0;
  while (lo <= ho) {
    int mid = (lo + ho) / 2;
    int cans = ok(mid);
    if (cans != -1) {
      sz = mid;
      lo = mid + 1;
    } else
      ho = mid - 1;
  }
  std::cout << sz << "\n";
  return 0;
}
