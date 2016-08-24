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
const int maxn = 5e5 + 5;
int main() {
  ios::sync_with_stdio(false);
  int a[26];
  rep(i, 0, 25) { std::cin >> a[i]; }
  string s;
  std::cin >> s;
  int h = 0;
  int n = s.size();
  rep(i, 0, n - 1) { h = max(h, a[s[i] - 'a']); }
  std::cout << n * h << "\n";
}
