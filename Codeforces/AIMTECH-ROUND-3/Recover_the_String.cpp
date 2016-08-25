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
  int a00, a01, a10, a11;
  std::cin >> a00 >> a01 >> a10 >> a11;
  map<int, int> m;
  rep(i, 0, 50000) m[i * (i - 1) / 2] = i;
  if (m.find(a00) == m.end() or m.find(a11) == m.end()) {
    std::cout << "Impossible"
              << "\n";
    return 0;
  }
  int zeros = a00 > 0 ? m[a00] : (a01 > 0 || a10 > 0) ? 1 : 0;
  int ones = a11 > 0 ? m[a11] : (a01 > 0 || a10 > 0) ? 1 : 0;
  if (a00 == 0 and a01 == 0 and a10 == 0 and a11 == 0) {
    std::cout << 0 << "\n";
    return 0;
  }
  if (1LL * zeros * ones < 1LL * a01 or 1LL * zeros * ones < 1LL * a10 or
      1LL * zeros * ones != (a01 + a10)) {
    std::cout << "Impossible"
              << "\n";
    return 0;
  }
  if (a01 == 0 and a10 == 0 and a11 == 0) {
    rep(i, 1, zeros) std::cout << 0;
    return 0;
  }
  if (a01 == 0 and a10 == 0 and a00 == 0) {
    rep(i, 1, ones) std::cout << 1;
    return 0;
  }
  while (zeros > 0 or ones > 0) {
    if (zeros > 0 and a01 >= ones) {
      printf("0");
      a01 -= ones;
      zeros--;
    }
    if (ones > 0 and a10 >= zeros) {
      printf("1");
      a10 -= zeros;
      ones--;
    }
  }
  return 0;
}
