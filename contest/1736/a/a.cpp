// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += abs(a[i] - b[i]);
  }
  int sa = std::count(a.begin(), a.end(), 1);
  int sb = std::count(b.begin(), b.end(), 1);
  std::cout << std::min(ans, 1 + std::abs(sa - sb)) << '\n';
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
