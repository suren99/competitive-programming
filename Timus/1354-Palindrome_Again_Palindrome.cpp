//0(n) solution
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
const int mod = 1e9 + 7;
const int h = 31;
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (1LL * a * b) % mod; }
int main() {
  ios::sync_with_stdio(false);
  string a;
  std::cin >> a;
  int n = (int)a.size();
  int p = 0, s = 0;
  int ans;
  rep(i, 0, n - 1) p = add(mul(p, h), a[i]);
  rrep(i, n - 1, 0) s = add(mul(s, h), a[i]);
  int pw[2 * n];
  pw[0] = 1;
  rep(i, 1, 2 * n - 1) pw[i] = mul(pw[i - 1], h);
  int prevs = 0;
  int prevp = 0;
  rep(i, 0, n - 1) {
    p = mul(p, h);
    prevs = mul(prevs, h);
    if (add(add(p, mul(a[i], pw[i])), prevp) ==
        add(s, add(mul(a[i], pw[n]), prevs))) {
      ans = i;
      break;
    }
    prevp = add(prevp, mul(a[i], pw[i]));
    prevs = add(prevs, mul(a[i], pw[n]));
  }
  string added = a.substr(0, ans + 1);
  reverse(added.begin(), added.end());
  std::cout << a + added << "\n";
  return 0;
}
