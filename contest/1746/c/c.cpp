// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) {
    std::cin >> x;
    --x;
  }
  std::vector<int> pos(n);
  for (int i = 0; i < n; ++i) pos[a[i]] = i;
  for (int i = 0; i < n; ++i) {
    std::cout << (pos[i] + 2 <= n ? pos[i] + 2 : 1) << ' ';
  }
  std::cout << '\n';
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
