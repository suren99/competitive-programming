//Author - suren99
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
const ll mod = (ll)1e9 + 7;
const int maxn = 1e5 + 5;
int n;
ll k;
int primes[3000001];
ll num[10000001];
ll inv(ll base, ll pw) {
  ll ans = 1;
  while (pw != 0) {
    if (pw & 1) {
      ans = (ans * base) % mod;
    }
    base = (base * base) % mod;
    pw /= 2;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin >> n >> k;
  rep(i, 0, n - 1) {
    int a;
    std::cin >> a;
    int tmp = a;
    for (int j = 2; j * j <= a; j++) {
      int cnt = 0;
      while (tmp % j == 0) {
        tmp /= j;
        cnt++;
      }
      primes[j] += cnt;
    }
    if (tmp > 1)
      primes[tmp]++;
  }
  ll ans = 1;
  ll den[k + 1];
  den[0] = 1;
  den[1] = 1;
  num[0] = 1;
  num[1] = 1;
  rep(i, 2, k) den[i] = (den[i - 1] * i) % mod;
  rep(i, 1, 10000000) num[i] = (num[i - 1] * i) % mod;
  rep(i, 2, 3000000) {
    if (primes[i] == 0)
      continue;
    ll num1 = num[primes[i] + k - 1];
    num1 = (num1 * inv(num[primes[i]], mod - 2)) % mod;
    ans = ((ans * num1) % mod * inv(den[k - 1], mod - 2)) % mod;
  }
  std::cout << ans << "\n";
  return 0;
}
