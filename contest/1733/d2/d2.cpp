// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#include <vector>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::string a, b;
  std::cin >> a >> b;
  std::vector<int> ab;
  if (x >= y) {
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        ab.emplace_back(i);
      }
    }
    if (ab.size() % 2) {
      std::cout << -1 << '\n';
      return;
    }
    if (ab.size() == 2 && ab[0] + 1 == ab[1]) {
      std::cout << std::min(x, 2 * y) << '\n';
    } else {
      std::cout << 1LL * ab.size() / 2 * y << '\n';
    }
  } else {

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
