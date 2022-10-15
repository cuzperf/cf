// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> son(n);
  std::vector<int> s(n);
  for (int i = 1; i < n; ++i) {
    int x;
    std::cin >> x;
    son[--x].emplace_back(i);
  }
  for (auto &x : s) std::cin >> x;
  std::vector<LL> ans(n);
  std::function<LL(int, int)> dfs = [&](int u, int c) -> LL {
    LL ret = 0;
    if (!son[u].empty()) {
      int szu = son[u].size();
      int cv = c / szu;
      int cu = c - cv * szu;
      std::vector<LL> a;
      a.reserve(szu);
      for (auto v : son[u]) {
        a.emplace_back(dfs(v, cv));
        ans[u] += ans[v];
      }
      std::sort(a.begin(), a.end(), std::greater<>());
      for (int i = 0; i < cu; ++i) {
        ans[u] += a[i];
      }
      ret += a[cu];
    }
    ans[u] += 1LL * c * s[u];
    ret += s[u];
    return ret;
  };
  dfs(0, k);
  std::cout << ans[0] << '\n';
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
