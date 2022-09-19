// https://github.com/cuzperf/cf
#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
#include <vector>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  if (std::is_sorted(a.begin(), a.end())) {
    std::cout << 0 << '\n';
    return;
  }
  std::cout << n - 1 << '\n';
  int x = n - 1;
  while (x >= 0 && a[x] % 2 != a[0] % 2) --x;
  for (int i = 0; i < x; ++i) if (a[i] % 2 == a[0] % 2) {
    std::cout << i + 1 << ' ' << x + 1 << '\n';
  }
  for (int i = 0; i < n; ++i) if (a[i] % 2 != a[0] % 2) {
    std::cout << 1 << ' ' << i + 1 << '\n';
  }
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
