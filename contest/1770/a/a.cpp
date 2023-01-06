// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  // fake for a[i] > b[j]
  std::vector<int> a(n + m - 1);
  for (auto &x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  LL ans;
  std::cin >> ans;
  ans += std::accumulate(a.begin() + m, a.end(), 0ll);
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
