// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  int ans = std::max(a.back() + a[1] - 2 * a[0], 2 * a.back() - a[n - 2] - a[0]);
  for (int i = 1; i < n - 1; ++i) {
    int cur = std::min(a[i] - a[i - 1], a[i + 1] - a[i]) + std::max(a[i] - a[0], a.back() - a[i]);
    ans = std::max(ans, cur);
  }
  for (int i = 1; i < n - 1; ++i) {
    ans = std::max(ans, a[i] + a.back() - 2 * a[i - 1]);
  }
  for (int i = n - 1; i > 1; --i) {
    ans = std::max(ans, a[i] * 2 - a[0] - a[i - 1]);
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
