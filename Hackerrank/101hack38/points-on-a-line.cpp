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
  int n;
  std::cin >> n;
  int ok1 = 1, ok2 = 1;
  int a, b;
  std::cin >> a >> b;
  rep(i, 1, n - 1) {
    int u, v;
    std::cin >> u >> v;
    if (u != a)
      ok1 = 0;
    if (v != b)
      ok2 = 0;
  }
  if (ok2 or ok1)
    std::cout << "YES"
              << "\n";
  else std::cout << "NO"
            << "\n";
  return 0;
}
