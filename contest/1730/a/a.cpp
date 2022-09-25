// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, c;
  std::cin >> n >> c;
  std::map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++mp[x];
  }
  int ans = 0;
  for (auto &[x, y] : mp) {
    ans += std::min(y, c);
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
