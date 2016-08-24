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
  int n;
  std::cin >> n;
  ll h[maxn];
  rep(i, 0, n - 1) std::cin >> h[i];
  int m;
  std::cin >> m;
  int mark[maxn];
  memset(mark, 0, sizeof(mark));
  rep(i, 0, m - 1) {
    int z;
    std::cin >> z;
    z--;
    mark[z]++;
  }
  ll sum = 0;
  int i = 0;
  while (i < n) {
    int j = i + 1;
    while (j < n and mark[j] == 0)
      j++;
    j = min(j, n);
    if (j == n) {
      rep(k, i, n - 1) sum += h[k];
      break;
    }
    ll cnt = 1;
    rrep(k, j - 1, i) {
      sum += min(h[k], cnt);
      cnt++;
    }
    i = j;
  }
  std::cout << sum << "\n";
  return 0;
}
