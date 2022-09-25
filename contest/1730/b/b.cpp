// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), t(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : a) x *= 2;
  for (auto &x : t) std::cin >> x;
  for (auto &x : t) x *= 2;
  auto f = [&](int x) -> std::pair<int, int> {
    int l = 0, r = 2e8;
    for (int i = 0; i < n; ++i) {
      int d = x - t[i];
      l = std::max(l, a[i] - d);
      r = std::min(r, a[i] + d);
    }
    return {l, r};
  };
  int l = 0, r = 3e8;
  while (l < r) {
    int m = (l + r) / 2;
    auto [x, y] = f(m);
    if (x > y) l = m + 1;
    else r = m;
  }
  auto [x, y] = f(r);
  assert(x == y);
  std::cout << x / 2;
  if (x & 1) std::cout << ".5";
  std::cout << '\n';
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
