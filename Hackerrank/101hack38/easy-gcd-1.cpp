#include <bits/stdc++.h>
#define ll long long
#define mk make_pair
#define x first
#define y second
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int main() {
  ios::sync_with_stdio(false);
  ll n, k;
  std::cin >> n >> k;
  ll a;
  std::cin >> a;
  ll val = a;
  rep(i, 0, n - 2) {
    std::cin >> a;
    val = __gcd(val, a);
  }
  ll l = val * (k / val);
  if (val % 2 == 0)
    l = max(l, 2 * (k / 2));
  for (ll i = 3; i * i <= val; i += 1) {
    if (val % i == 0) {
      l = max(l, i * (k / i));
    }
  }
  std::cout << l << "\n";
  return 0;
}
