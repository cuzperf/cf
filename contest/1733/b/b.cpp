// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  if (x > y) std::swap(x, y);
  if (x >= 1) {
    std::cout << -1 << '\n';
    return;
  }
  if (y == 0 || (n - 1) % y != 0) {
    std::cout << -1 << '\n';
  } else {
    for (int i = 2; i <= n; i += y) {
      for (int j = 0; j < y; ++j) {
        std::cout << i << ' ';
      }
    }
    std::cout << '\n';
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
