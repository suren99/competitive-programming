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
int main() {
  ios::sync_with_stdio(false);
  int n, b, d;
  std::cin >> n >> b >> d;
  ll a[n];
  rep(i, 0, n - 1) std::cin >> a[i];
  ll now = 0;
  int ans = 0;
  rep(i, 0, n - 1) {
    if (a[i] > b)
      continue;
    if (now + a[i] > d) {
      ans++;
      now = 0;
    } else
      now += a[i];
  }
  std::cout << ans << "\n";
  return 0;
}
