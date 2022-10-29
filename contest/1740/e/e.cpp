// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

using pii = std::pair<int, int>;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  std::vector<std::vector<int>> e(n);
  for (int i = 1; i < n; ++i) {
    std::cin >> p[i];
    --p[i];
    e[p[i]].emplace_back(i);
  }
  std::function<pii(int)> dfs = [&](int u) -> pii {
    if (e[u].empty()) return {1, 1};
    int p1 = 0, p2 = 0;
    for (auto v : e[u]) {
      auto [x, y] = dfs(v);
      p1 += x;
      p2 = std::max(p2, y);
    }
    return {std::max(p1, p2 + 1), p2 + 1};
  };
  std::cout << dfs(0).first << '\n';
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
