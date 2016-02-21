#include <bits/stdc++.h>
#define pb push_back
#define x first
#define ll long long
#define mk make_pair
#define y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define inf INT_MAX
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
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
  int t;
  std::cin >> t;
  while (t--) {
    ll n, d;
    std::cin >> d >> n;
    rep(i, 0, d - 1) { n = n * (n + 1LL) / 2LL; }
    std::cout << n << "\n";
  }
  return 0;
}
