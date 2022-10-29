// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  LL sm = 0;
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    if (x > y) std::swap(x, y);
    sm += x;
    mx = std::max(mx, y);
  }
  std::cout << (sm + mx) * 2 << '\n';
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
