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
string s;
int n;
int main() {
  ios::sync_with_stdio(false);
  std::cin >> s;
  n = (int)s.size();
  int prev = -1;
  string t = s;
  rep(i, 0, n - 1) {
    if (prev == -1 and s[i] != 'a') {
      prev = i;
      s[i] = s[i] - 1;
    } else if (prev != -1) {
      if (s[i] == 'a')
        break;
      else
        s[i] -= 1;
    }
  }
  if (s == t) {
    if (s[n - 1] == 'a')
      s[n - 1] = 'z';
    else
      s[n - 1] -= 1;
  }
  std::cout << s << "\n";
  return 0;
}
