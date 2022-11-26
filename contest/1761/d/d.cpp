// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// n = 0
// f[1] = (1, 0, 0, 0)
// g[1] = (0, 0, 0, 0)

// n = 1
// (0, 0), (1, 0), (1, 0), (1, 1)
// f[1] = (3, 0, 0, 0, 0)
// g[1] = (0, 1, 0, 0, 0)

// n = 2
// (0, 0), (0, 1), (1, 0), (1, 1), (0, 2), (2, 0), (1, 2), (2, 1)
// (2, 2), (0, 3), (3, 0), (1, 3), (3, 1), (2, 3), (3, 2), (3, 3)
// f[2] = (9, 1, 0, 0)
// g[2] = (0, 3, 3, 0)

// a, b < 2^n
// f[n] a + b < 2^n
// g[n] a + b >= 2^n

// a, b < 2^{n + 1}
// f[n + 1] = 3 * f[n][k] + g[n][k]
// g[n + 1] = 3 * g[n][k - 1] + f[n][k - 1]
constexpr unsigned M = 1e9 + 7;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<unsigned> f{1}, g{0};
  for (int i = 1; i <= n; ++i) {
    std::vector<unsigned> ff(i + 1), gg(i + 1);
    for (int j = 0; j < i; ++j) {
      ff[j] = (f[j] * 3 + g[j]) % M;
      gg[j + 1] = (g[j] * 3 + f[j]) % M;
    }
    std::swap(f, ff);
    std::swap(g, gg);
  }
  std::cout << (f[k] + g[k]) % M << '\n';
}


int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
