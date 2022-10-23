// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

constexpr int M = 998244353;
int powMod(int x, int n = M - 2) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % M;
    n >>= 1;   x = 1LL * x * x % M;
  }
  return r;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int all = 1LL * n * (n - 1) / 2 % M;
  int cnt = 0, l = 0, r = n - 1;
  while (l < r) {
    while (l < r && a[l] == 0) ++l;
    while (r > l && a[r] == 1) --r;
    if (l < r) ++cnt;
    ++l;
    --r;
  }
  int ans = 0;
  for (int i = 1; i <= cnt; ++i) {
    // x = i*i / all * (1 + t) + (1 - i * i / all) * (1 + x)
    // x = t + all / i * i;
    int invi = powMod(i);
    ans = (ans + 1LL * all * invi % M * invi) % M;
  }
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
