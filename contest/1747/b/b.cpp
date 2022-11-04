// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// BANBANBAN
// 123456789abc
// BANBANBANBAN

// BNNBNN BAABAA
// BAN BAN BAN
// BNN BAN BAA
// BNN BNA BAA
// BAN BAN

void solve() {
  int n;
  std::cin >> n;
  std::cout << (n + 1) / 2 << '\n';
  for (int i = 0; i < n - 1 - i; ++i) {
    std::cout << 3 * i + 2 << ' ' << 3 * (n - i) << '\n';
  }
  if (n & 1) {
    std::cout << 3 * (n / 2) + 2 << ' ' << 3 * (n / 2) + 3 << '\n';
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
