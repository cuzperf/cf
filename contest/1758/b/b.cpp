// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  if (n & 1) {
    for (int i = 0; i < n; ++i) std::cout << 1 << ' ';
  } else {
    std::cout << 1 << ' ' << 3 << ' ';
    for (int i = 2; i < n; ++i) std::cout << 2 << ' ';
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
