// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  if (std::accumulate(a.begin(), a.end(), 0) % 2 == 0) {
    std::cout << 0 << '\n';
    return;
  }
  int ans = INT_MAX;
  for (auto x : a) {
    int cnt = 1;
    while ((x - x / 2) % 2 == 0) {
      ++cnt;
      x /= 2;
    }
    ans = std::min(ans, cnt);
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
