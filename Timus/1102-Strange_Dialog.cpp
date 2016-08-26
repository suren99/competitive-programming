// 0(n)-DFA solution
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
const int mod = 1e9 + 7;
const int maxn = 1e7 + 5;
int main() {
  ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  int g[20][30];
  memset(g, -1, sizeof(g));
  g[0]['o' - 97] = 1;
  g[1]['u' - 97] = 2;
  g[2]['t' - 97] = 3;
  g[3]['p' - 97] = 4;
  g[4]['u' - 97] = 5;
  g[5]['t' - 97] = 6;
  g[6]['o' - 97] = 7;
  g[7]['n' - 97] = 10;
  g[10]['e' - 97] = 0;
  g[0]['i' - 97] = 8;
  g[8]['n' - 97] = 3;
  g[0]['p' - 97] = 12;
  g[12]['u' - 97] = 13;
  g[13]['t' - 97] = 14;
  g[14]['o' - 97] = 15;
  g[15]['n' - 97] = 0;
  g[1]['n' - 97] = 9;
  g[9]['e' - 97] = 0;
  g[3]['o' - 97] = 1;
  g[3]['i' - 97] = 8;
  g[6]['p' - 97] = 12;
  g[6]['i' - 97] = 8;
  g[7]['u' - 97] = 2;
  g[10]['p' - 97] = 12;
  g[10]['o' - 97] = 1;
  g[10]['i' - 97] = 8;
  while (t--) {
    string s;
    std::cin >> s;
    int n = (int)s.size();
    int cur = 0;
    rep(i, 0, n - 1) {
      if (cur == -1)
        break;
      cur = g[cur][s[i] - 'a'];
    }
    if (cur == 0 or cur == 3 or cur == 6 or cur == 10)
      std::cout << "YES"
                << "\n";
    else
      std::cout << "NO"
                << "\n";
  }
  return 0;
}
